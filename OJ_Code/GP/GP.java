import java.util.*;

class GeneticAlgorithm {
    private final int populationNumber = 60; //数量
    private final double crossProbability = 0.95;  //交叉概率
    private final double mutationProbability = 0.05;  //突变概率
    private int jobNumber;  //工作数
    private int machineNumber; //机器数
    private int processNumber; //工序数
    private int chromosomeSize; //染色体大小


    private int[][] machineMatrix = new int[1024][1024];   //机器矩阵
    private int[][] timeMatrix = new int[1024][1024];  //时间矩阵
    private int[][] processMatrix = new int[1024][1024]; //工序矩阵


    private Set<Gene> geneSet = new HashSet<>();    //基因集
    private Random random = new Random();  //随机数


    //遗传算法
    public GeneticAlgorithm(int jobNumber, int machineNumber) {
        this.jobNumber = jobNumber;
        this.machineNumber = machineNumber;
        for (int[] matrix : this.machineMatrix) Arrays.fill(matrix, -1);//将数组中元素值定义为-1
        for (int[] process : this.processMatrix) Arrays.fill(process, -1); //同理
    }

    private List<Integer> makeList(int n) {
        List<Integer> result = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) result.add(i);
        return result;
    }

    private Integer[] filterArray(Integer[] arr, int filterVal) {
        List<Integer> result = new ArrayList<Integer>();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != filterVal) {
                result.add(arr[i]);
            }
        }
        return result.toArray(new Integer[0]);
    }

    // 初始化种群
    public  void initialPopulation() {
        for (int i = 0; i < populationNumber; i ++) {
            Gene g = new Gene();
            int size = jobNumber * machineNumber;
            List<Integer> indexList = makeList(size);
            Integer[] chromosome = new Integer[size];
            Arrays.fill(chromosome, -1);
            for (int j = 0; j < jobNumber; j++) {
                for (int k = 0; k < machineNumber; k ++) {
                    int index = random.nextInt(indexList.size());
                    int val = indexList.remove(index);
                    if (processMatrix[j][k] != -1) {
                        chromosome[val] = j;
                    }
                }
            }
            g.chromosome = filterArray(chromosome, -1);
            g.fitness = calculateFitness(g).fulfillTime;
            geneSet.add(g);
        }
    }

    public List<Integer> subArray(Integer[] arr, int start, int end) {
        List<Integer> list = new ArrayList<>();
        for (int i = start; i < end; i++) list.add(arr[i]);
        return list;
    }

    // 计算适应度
    public Result calculateFitness(Gene g) {
        Result result = new Result();
        for (int i = 0; i < g.chromosome.length; i ++) {
            int jobId = g.chromosome[i];
            int processId = result.processIds[jobId];
            int machineId = machineMatrix[jobId][processId];
            int time = timeMatrix[jobId][processId];
            result.processIds[jobId] += 1;
            result.startTime[jobId][processId] = processId ==0 ? result.machineWorkTime[machineId] :
                    Math.max(result.endTime[jobId][processId - 1], result.machineWorkTime[machineId]);
            result.machineWorkTime[machineId] = result.startTime[jobId][processId] + time;
            result.endTime[jobId][processId] = result.machineWorkTime[machineId];
            result.fulfillTime = Math.max(result.fulfillTime, result.machineWorkTime[machineId]);

        }
        return result;
    }
    // 交叉算子
    private Gene crossGene(Gene g1, Gene g2) {
        List<Integer> indexList = makeList(chromosomeSize);
        int p1 = indexList.remove(random.nextInt(indexList.size()));
        int p2 = indexList.remove(random.nextInt(indexList.size()));

        int start = Math.min(p1, p2);
        int end = Math.max(p1, p2);

        List<Integer> proto = subArray(g1.chromosome, start, end + 1);
        List<Integer> t = new ArrayList<>();
        for (Integer c : g2.chromosome) t.add(c);
        for (Integer val : proto) {
            for (int i = 0; i < t.size(); i++) {
                if (val.equals(t.get(i))) {
                    t.remove(i);
                    break;
                }
            }
        }

        Gene child = new Gene();
        proto.addAll(t.subList(start, t.size()));
        List<Integer> temp = t.subList(0, start);
        temp.addAll(proto);
        child.chromosome = temp.toArray(new Integer[0]);
        child.fitness = (double) calculateFitness(child).fulfillTime;
        return child;
    }
    // 突变算子
    public Gene mutationGene(Gene gene, int n) {
        List<Integer> indexList = makeList(chromosomeSize);
        for (int i = 0; i < n; i++) {
            int a = indexList.remove(random.nextInt(indexList.size()));
            int b = indexList.remove(random.nextInt(indexList.size()));
            int t = gene.chromosome[a];
            gene.chromosome[a] = gene.chromosome[b];
            gene.chromosome[b] = t;
        }
        gene.fitness = calculateFitness(gene).fulfillTime;
        return gene;
    }

    // 选择个体
    public Gene selectGene(int n) {
        List<Integer> indexList = makeList(geneSet.size());
        Map<Integer, Boolean> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.put(indexList.remove(random.nextInt(indexList.size())), true);
        }
        Gene bestGene = new Gene(0xfffff);
        int i = 0;
        for (Gene gene : geneSet) {
            if (map.containsKey(i)) {
                if (bestGene.fitness > gene.fitness) {
                    bestGene = gene;
                }
            }
            i ++;
        }
        return bestGene;
    }

    public Result run(List<List<Integer[]>> job) {
        int jobSize = job.size();

        for (int i = 0; i < jobSize; i ++) {
            chromosomeSize += job.get(i).size();
            processNumber = Math.max(processNumber, job.get(i).size());
            for (int j = 0; j < job.get(i).size(); j ++) {
                machineMatrix[i][j] = job.get(i).get(j)[0];
                timeMatrix[i][j] = job.get(i).get(j)[1];

            }
        }

        for (int i = 0; i < jobSize; i++) {
            for (int j = 0;j < processNumber; j++){
                if (machineMatrix[i][j] != -1) {
                    processMatrix[i][machineMatrix[i][j]] = j;
                }
            }
        }
        initialPopulation();
        for (int i = 0; i < populationNumber; i++) {
            double p = (double) random.nextInt(100) / 100.0;
            if (p < mutationProbability) {
                int index = random.nextInt(geneSet.size());
                int k = 0;
                for (Gene gene : geneSet) {
                    if (k == index) {
                        mutationGene(gene);
                        break;
                    }
                    k ++;
                }
            } else {
                Gene g1 = selectGene(), g2 = selectGene();
                Gene child1 = crossGene(g1, g2), child2 = crossGene(g2, g1);
                geneSet.add(child1);
                geneSet.add(child2);
            }
        }
        Gene bestGene = new Gene(0xffffff);
        for (Gene gene : geneSet) {
            if (bestGene.fitness > gene.fitness) {
                bestGene = gene;
            }
        }
        return calculateFitness(bestGene);
    }

    public Gene selectGene() {
        return selectGene(3);
    }

    public Gene mutationGene(Gene gene) {
        return mutationGene(gene, 2);
    }

    static public void main(String[] args) {
        List<List<Integer[]>> job = Arrays.asList(
                Arrays.asList(new Integer[]{0, 3}, new Integer[]{1, 2}, new Integer[]{2, 2}),
                Arrays.asList(new Integer[]{0, 2}, new Integer[]{2, 1}, new Integer[]{1, 4}),
                Arrays.asList(new Integer[]{1, 4}, new Integer[]{2, 3})
        );

        int n = 3, m = 3;
        GeneticAlgorithm ga = new GeneticAlgorithm(n, m);
        Result result = ga.run(job);
        int processNumber = ga.processNumber;

        int[][] machineMatrix = ga.machineMatrix;
        System.out.println(result.fulfillTime);

        for (int i = 0; i < n; i++) {
            for (int j = 0 ; j < processNumber; j++) {
                if (machineMatrix[i][j] != -1) {
                    System.out.println(String.format("job: %d, process: %d, machine: %d, startTime: %d, endTime: %d",
                            i, j, machineMatrix[i][j], result.startTime[i][j], result.endTime[i][j]));
                }
            }
        }
    }
}



class Gene {
    public double fitness;
    public Integer[] chromosome;
    public Gene() {
        fitness = 0;
    }
    public Gene(double fitness) {this.fitness = fitness;}
}

class Result {
    public int fulfillTime = 0;
    public int[] machineWorkTime = new int[1024];
    public int[] processIds = new int[1024];
    public int[][] endTime = new int[1024][1024];
    public int[][] startTime = new int[1024][1024];
}
