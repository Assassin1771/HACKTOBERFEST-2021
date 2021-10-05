// C++ program to find the shortest path between
// a given source cell to a destination cell.
#include <bits/stdc++.h>
using namespace std;
int ROW=0;
int COL=0;

//To store matrix cell coordinates
struct Point
{
    int x;
    int y;
};

// A Data Structure for queue used in BFS
struct queueNode
{
    Point pt;  // The coordinates of a cell
    int dist;  // cell's distance of from the source
};

// check whether given cell (row, col) is a valid
// cell or not.
bool isValid(int row, int col)
{
    // return true if row number and column number
    // is in range
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL);
}

// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

// function to find the shortest path between
// a given source cell to a destination cell.
int BFS(vector<vector<int> > mat, Point src, Point dest)
{
    // check source and destination cell
    // of the matrix have value 1
    if (!mat[src.x][src.y] || !mat[dest.x][dest.y])
        return -1;

    bool visited[ROW][COL];
    memset(visited, false, sizeof visited);

    // Mark the source cell as visited
    visited[src.x][src.y] = true;

    // Create a queue for BFS
    queue<queueNode> q;

    // Distance of source cell is 0
    queueNode s = {src, 0};
    q.push(s);  // Enqueue source cell

    // Do a BFS starting from source cell
    while (!q.empty())
    {
        queueNode curr = q.front();
        Point pt = curr.pt;

        // If we have reached the destination cell,
        // we are done
        if (pt.x == dest.x && pt.y == dest.y)
            return curr.dist;

        // Otherwise dequeue the front
        // cell in the queue
        // and enqueue its adjacent cells
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];

            // if adjacent cell is valid, has path and
            // not visited yet, enqueue it.
            if (isValid(row, col) && mat[row][col] &&
               !visited[row][col])
            {
                // mark cell as visited and enqueue it
                visited[row][col] = true;
                queueNode Adjcell = { {row, col},
                                      curr.dist + 1 };
                q.push(Adjcell);
            }
        }
    }

    // Return -1 if destination cannot be reached
    return -1;
}

// Driver program to test above function
int main()
{
    cout<<"CAN TUSHAR SAVE ABHINAY'S LIFE??"<<endl<<endl;
    int r=0,c=0;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    cout<<"Enter Number of Row(s)"<<endl;
    cin>>r;
    cout<<endl;
    cout<<"Enter Number of Column(s)"<<endl;
    cin>>c;
    cout<<endl;
    vector<vector<int> > mat( r , vector<int> (c));
    cout<<"Enter the Matrix"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }
    cout<<endl;

    int sr=0,sc=0,dr=0,dc=0;

    cout<<"Enter Start Point (Coordinates)"<<endl;
    cin>>sr;
    cin>>sc;
    cout<<endl;
    Point source = {sr, sc};
    cout<<"Enter End Point (Coordinates)"<<endl;
    cin>>dr;
    cin>>dc;
    cout<<endl;
    cout<<endl;
    Point dest = {dr, dc};
    ROW=r;
    COL=c;
    int dist = BFS(mat, source, dest);

    int tt=dist;
    tt=tt/60;
    double time=dist/(60.0);

    if(tt<=15&&time>=0&&time<=1)
        cout<<"TUSHAR SAVES ABHINAY AS HE TOOK "<<dist<<" SECOND(s) TO REACH :) "<<endl;
    else if(tt<=15&&time>1)
        cout<<"TUSHAR SAVES ABHINAY AS HE TOOK "<<time<<" MINUTE(s) TO REACH :) "<<endl;
    else
        cout<<"ABHINAY IS NO MORE WITH US :("<<endl;

    return 0;
}
