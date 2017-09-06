/**
 * @File move_generator.h
 * @Brief file_description
 * Details:
 * @Author guohainan
 * @Version v0.0.1
 * @date 2017-09-06 00:23:51
 */
#ifndef gomoku__MOVE_GENERATOR_H__
#define gomoku__MOVE_GENERATOR_H__

#include "gomoku/chess_borad.h"

namespace gomoku
{

//走法产生器接口类
class MoveGeneratorInterface
{
public:
    /**
     * 给定一个棋局， 产生所有下法
     * 输入：
     * chessBoard 棋局
     * arrMoves 输出的走法数组
     * arrScore 输出的走法评分的数组， 如果为NULL， 不设置
     * iMaxMoves 最大产生的走法数
     * 输出：
     * 产生的走法个数
     **/
    virtual size_t generateAllMoves(const ChessBord & chessBord
        , ChessMove * arrMoves
        , TScore * arrScore
        , size_t iMaxMoves) = 0;
};


}//namespace gomoku


#endif //gomoku__MOVE_GENERATOR_H__
