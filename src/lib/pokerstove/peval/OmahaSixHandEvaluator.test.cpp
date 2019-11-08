#include "OmahaSixHandEvaluator.h"
#include <gtest/gtest.h>
#include <iostream>

using namespace pokerstove;
using namespace std;

TEST(OmahaSixHandEvaluator, Construct)
{
    OmahaSixHandEvaluator eval;
    EXPECT_EQ(true, eval.usesSuits());
    EXPECT_EQ(5, eval.boardSize());
}

TEST(OmahaSixHandEvaluator, RankEval)
{
    OmahaSixHandEvaluator oeval;
    CardSet hand("AcKhQsJdTc9h");
    CardSet board("7c8c2s");
    PokerEvaluation eval = oeval.evaluateRanks(hand, board);
    EXPECT_EQ(TWO_PAIR, eval.type());
    EXPECT_EQ(Rank("3"), eval.majorRank());
    EXPECT_EQ(Rank("2"), eval.minorRank());
}
