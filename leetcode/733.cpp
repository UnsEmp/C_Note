#include <bits/stdc++.h>
using namespace std;
int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(vector<vector<int>> & image, int original, int sr, int sc, int newColor) {
    //  cout << sr << " " <<sc<< endl;
    if(sr >= 0 && sc >= 0  && sr < image.size() && sc < image[0].size() && image[sr][sc] == original) {
        image[sr][sc] = newColor;
        if(new)
    }
    else
        return ;
    for(int i = 0;i < 4;i++) {
        // cout << sr + direction[i][0] << " " <<sc + direction[i][1] << endl;
        dfs(image, original, sr + direction[i][0], sc + direction[i][1], newColor);
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int original = image[sr][sc];
    // image[sr][sc] = newColor;
    dfs(image, original, sr, sc, newColor);
    dfs()
    return image;
}


int main() {
    vector<vector<int>> image = {{0,0,0}, {0,1,1}}; 
    floodFill(image, 1, 1, 1);
    rand();
    return 0;
}