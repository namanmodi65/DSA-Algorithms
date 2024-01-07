vector<vector<int>> towerOfHanoi(int n,int source = 1,int helper = 2,int destination)
{
    vector<vector<int>> moves;

    if(n==1){
        moves.push_back({source,destination});
        return moves;
    }

    vector<vector<int>> subMoves1 = towerOfHanoi(n-1,source,destination,helper);
    moves.insert(moves.end(),subMoves1.begin(),subMoves1.end());
    
    moves.push_back({source, destination});


    vector<vector<int>> subMoves2 = towerOfHanoi(n-1,helper,source,destination);
    moves.insert(moves.end(),subMoves2.begin(),subMoves2.end());

    return moves;
}