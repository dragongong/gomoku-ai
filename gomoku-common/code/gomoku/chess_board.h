/**
 * @File gomoku/chess_borad.h
 * @Brief file_description
 * Details:
 * @Author guohainan
 * @Version v0.0.1
 * @date 2017-09-05 14:38:00
 */
#ifndef gomoku__CHESS_BORAD_H__
#define gomoku__CHESS_BORAD_H__

#include "gomoku/constant.h"

namespace gomoku
{

/**
 * 走法
 **/
struct ChessMove
{
    TChessPos row;
    TChessPos col;
    TChessColor color;
    ChessMove()
    {
        row = col = color = (char) 0;
    }
    ChessMove(TChessColor player, TChessPos r, TChessPos c)
        : row(r), col(c), color(player)
    {
    }
    inline string toString() const
    {
        char szTmp[32] = {0};
        snprintf(szTmp, sizeof(szTmp) - 1, "%c put [%d, %d]", color, (int) row, (int) col);
        return szTmp;
    }
};

struct ScoredMove
{
    ChessMove move;
    TScore score;
    bool operator < (const ScoredMove & other) const
    {
        return score < other.score;
    }
};

/**
 * 棋盘
 **/
struct ChessBoard
{
public:
    ChessBoard();
    /**
     * 判断游戏是否结束
     **/
    bool isGameOver()const;
    /**
     * 根据最后一步判断棋局是否结束
     **/
    bool isGameOver(const ChessMove & lastStep)const;
    /**
     * 判断谁是赢家
     **/
    TChessColor getWinColor()const;
    /**
     * 打印棋盘
     **/
    void printChessBord()const;
    void printChessBord(const ChessMove & move)const;
public:
    //inline public function
    /**
     * 下棋， isCheckRule 是否校验该步是否合法
     **/
    inline bool playChess(const ChessMove & move, bool isCheckRule = false);
    /**
     * 判断是否合法
     **/
    inline bool isValidMove(const ChessMove & move) const;
    /**
     * 获取最后一手的玩家颜色
     **/
    inline TChessColor getLastPlayerColor()const;
public:
    //棋盘点阵信息
    TChessColor m_board[CHESS_BORD_SIZE][CHESS_BORD_SIZE];
    //下一个玩家颜色
    TChessColor m_nextPlayerColor;
    int m_iBlankChessCnt;
};


//#######################
/**
 * 下棋， isCheckRule 是否校验该步是否合法
 **/
inline bool ChessBoard::playChess(const ChessMove & move, bool isCheckRule )
{
    if(!IsValidPos(move.row, move.col))
    {
                //printf("%d\n", __LINE__);
        return false;
    }
    if(m_board[move.row][move.col] != COLOR_BLANK)
    {
                //printf("%d\n", __LINE__);
        return false;
    }
    if(isCheckRule && ! isValidMove(move) )
    {
                //printf("%d\n", __LINE__);
        return false;
    }
    m_board[move.row][move.col] = move.color;
    m_nextPlayerColor = GetReverseColor(m_nextPlayerColor);
    m_iBlankChessCnt --;
    return true;
}
/**
 * 判断是否合法
 **/
inline bool ChessBoard::isValidMove(const ChessMove & move) const
{
    if(m_nextPlayerColor != move.color)
    {
      //  printf("%d\n", __LINE__);
        return false;
    }
    if(isGameOver())
    {
                //printf("%d\n", __LINE__);
        return false;
    }
    if(m_board[move.row][move.col] != COLOR_BLANK)
    {
                //printf("%d\n", __LINE__);
        return false;
    }
    if(!IsValidPos(move.row, move.col))
    {
                //printf("%d\n", __LINE__);
        return false;
    }
    return true;
}
/**
 * 获取最后一手的玩家颜色
 **/
inline TChessColor ChessBoard::getLastPlayerColor()const
{
    return GetReverseColor(m_nextPlayerColor);
}

}//namespace gomoku

#endif //gomoku__CHESS_BORAD_H__