#include "bits/stdc++.h"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"
#include "Solver/IDAstarSolver.h"
#include "Model/RubiksCube3dArray.cpp"

using namespace std;

int main() {
    // // 3D Array Cube Solver using IDA* and Pattern Database

    string fileName = "C:\\Users\\user\\CLionProjects\\rubiks-cube-solver\\Databases\\cornerDepth5V1.txt";

    RubiksCube3dArray cube;
    auto shuffleMoves = cube.randomShuffleCube(5);
    cube.print();
    for (auto move: shuffleMoves) cout << cube.getMove(move) << " ";
    cout << "\n";

    // // IDA* Solver
    // IDAstarSolver<RubiksCube3dArray, Hash3d> idaStarSolver(cube, fileName);
    // auto moves = idaStarSolver.solve();

    // idaStarSolver.rubiksCube.print();
    // for (auto move: moves) cout << cube.getMove(move) << " ";
    // cout << "\n";

    
    // DFS Solver
    DFSSolver<RubiksCube3dArray, Hash3d> dfsSolver(cube, 8);
    auto dfs_moves = dfsSolver.solve();
    for (auto move: dfs_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    dfsSolver.rubiksCube.print();
/*
    // BFS Solver
    BFSSolver<RubiksCube3dArray, Hash3d> bfsSolver(cube);
    auto bfs_moves = bfsSolver.solve();
    for (auto move: bfs_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    bfsSolver.rubiksCube.print();

    // IDDFS Solver
    IDDFSSolver<RubiksCube3dArray, Hash3d> iddfsSolver(cube, 7);
    auto iddfs_moves = iddfsSolver.solve();
    for (auto move: iddfs_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    iddfsSolver.rubiksCube.print();
    */

    return 0;
}