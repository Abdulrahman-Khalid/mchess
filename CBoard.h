#include <vector>
#include <string>

#include "CMove.h"
#include "CMoveList.h"

#ifndef _C_BOARD_H_
#define _C_BOARD_H_

// The board is represented as an array of 120 elements.
// arranged in 12 rows and 10 columns.
// The following diagram shows the numbering of the elements.
// Note: The square A1 is element number 21
//
// 111 118 112 113 114 115 116 117 118 119
// 100 108 102 103 104 105 106 107 108 109
//  90  A8  92  93  94  95  96  97  H8  99
//  80  88  82  83  84  85  86  87  88  89
//  70  71  72  73  74  75  76  77  78  79
//  60  61  62  63  64  65  66  67  68  69
//  50  51  52  53  54  55  56  57  58  59
//  40  41  42  43  44  45  46  47  48  49
//  30  31  32  33  34  35  36  37  H2  39
//  20  A1  22  23  24  25  26  27  H1  29
//  10  11  12  13  14  15  16  17  18  19
//   0   1   2   3   4   5   6   7   8   9
//
// Each element contains one of the following values:
//   0  :  Empty
//   1  :  White Pawn
//   2  :  White Knight
//   3  :  White Bishop
//   4  :  White Rook
//   5  :  White Queen
//   6  :  White King
//   -1 :  Black Pawn
//   -2 :  Black Knight
//   -3 :  Black Bishop
//   -4 :  Black Rook
//   -5 :  Black Queen
//   -6 :  Black King
//   99 :  INVALID

enum // Squares
{
    A8 = 91, B8, C8, D8, E8, F8, G8, H8,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
};

enum // Directions
{
    N = 10, S = -10, E = -1, W = 1,
    NW = 11, SW = -9, NE = 9, SE = -11
};

/***************************************************************
 * declaration of CBoard
 ***************************************************************/
class CBoard
{
    public:
        CBoard() { newGame(); }

        // Copy constructor
        CBoard(const CBoard& rhs);

        void newGame();
        void find_legal_moves(CMoveList &moves) const;
        void make_move(const CMove &move);
        void undo_move(const CMove &move);
        int  get_value();
        bool IsMoveValid(CMove &move);
        bool isKingInCheck() const;
        bool isOtherKingInCheck() const; // Used by perft

        friend std::ostream& operator <<(std::ostream &os, const CBoard &rhs);

    private:
        bool isSquareThreatened(const CSquare& sq) const;
        void swap_sides() {m_side_to_move = -m_side_to_move;}

        std::vector<int8_t>   m_board;
        int m_side_to_move;
        int m_material;

}; // end of class CBoard

#endif // _C_BOARD_H_
