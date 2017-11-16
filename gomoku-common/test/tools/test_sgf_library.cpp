/**
 * @File test_chess_board.cpp
 * @Brief file_description
 * Details:
 * @Author guohainan
 * @Version v0.0.1
 * @date 2017-09-06 23:33:16
 */
#include "gtest/gtest.h"

#define UNIT_TEST true
#include "tools/sgf_library.h"

using namespace gomoku;
using namespace tools;

TEST(SgfLibrary, parse)
{
    string line = "(;US[save from iwzq.com]CP[第二轮【2004.8.7】第二桌第一盘]5A[]PW[[荡漾不羁]情义两重天]PB[星月王族之姽婳]DT[2007-2-12]RE[和棋]SW[False]SZ[15];B[hh];W[hi];B[hf];W[ij];B[if];W[ii];B[gi];W[gh];B[jk];W[ig];B[ih];W[kg];B[gf];W[jf];B[fh];W[ef];B[fg];W[hj];B[jh];W[kj];B[jj];W[ji];B[kh];W[lh];B[ie];W[gg];B[li];W[he];B[fe];W[ff];B[fj];W[ej];B[di];W[fi];B[dk];W[dh];B[eg];W[eh];B[ed];W[hg];B[jg];W[mj];B[hk];W[ek];B[el];W[cf];B[dg];W[df];B[bf];W[cg];B[bh];W[fm];B[mi];W[im];B[ik];W[kk];B[gm];W[hl];B[jl];W[jd];B[ke];)";
    ChessBoard board;
    SgfLibrary sl;
    EXPECT_TRUE(sl.parse(line.c_str(), board));
    board.printChessBord();
}