#include <gtest/gtest.h>
#include <vector>
#include <tuple>

#include "element.h"
#include "board.h"
#include "movemap.h"

TEST(Sphere, Constructors) {
  Sphere sphere;

  for (auto element : ELEMENTLIST) {
    EXPECT_EQ(sphere.at(element), 0);
  }

  Sphere sphere2({Element::FIRE});
  for (auto element : ELEMENTLIST) {
    EXPECT_EQ(sphere2.at(element), element == Element::FIRE);
  }

  Sphere sphere3({{Element::WATER, 1}, {Element::EARTH, 2}});
  for (auto element : ELEMENTLIST) {
    if (element == Element::WATER) {
      EXPECT_EQ(sphere3.at(element), 1);
    }
    else if (element == Element::EARTH)
    {
      EXPECT_EQ(sphere3.at(element), 2);
    }
    else {
      EXPECT_EQ(sphere3.at(element), 0);
    }
  }

}

TEST(Sphere, CountTest) {
  Sphere sphere;

  for (auto element : ELEMENTLIST) {
    EXPECT_EQ(sphere.count(element), 0);
  }

  Sphere sphere2({Element::FIRE});
  for (auto element : ELEMENTLIST) {
    EXPECT_EQ(sphere2.count(element), element == Element::FIRE);
  }

  Sphere sphere3({{Element::WATER, 1}, {Element::EARTH, 2}});
  for (auto element : ELEMENTLIST) {
    if (element == Element::WATER) {
      EXPECT_EQ(sphere3.count(element), 1);
    }
    else if (element == Element::EARTH)
    {
      EXPECT_EQ(sphere3.count(element), 2);
    }
    else {
      EXPECT_EQ(sphere3.count(element), 0);
    }
  }
  EXPECT_EQ(sphere3.count(), 3);
}



TEST(Board, BoardInitGemCounts) {
  Board board;
  
  for (auto element : ELEMENTLIST) {
    EXPECT_EQ(board.count(element, element), 1);
    EXPECT_EQ(board.count(element, ~element), 0);
  }

}

TEST(Board, MoveMapTest) {
  std::vector<Move> moves = {{Element::FIRE, Element::FIRE, Element::WATER}, {Element::EARTH, Element::EARTH, Element::LIGHTNING}, {Element::EARTH, Element::EARTH, Element::LIGHTNING}};
  
  MoveMap moveMap(moves);
  EXPECT_EQ(moveMap.inputCount(), 3);
  EXPECT_EQ(moveMap.inputCount(Element::EARTH, Element::EARTH), 2);
  EXPECT_EQ(moveMap.outputCount(), 3);
  EXPECT_EQ(moveMap.outputCount(Element::LIGHTNING, Element::EARTH), 2);
}

TEST(Board, SetSphereTest) {
  Board board;
  Sphere expectedSphere({Element::FIRE});

  EXPECT_TRUE(board.getSphere(Element::FIRE).equal(expectedSphere));

  Sphere sphere({Element::FIRE, Element::FIRE, Element::LIGHTNING});
  board.setSphere(Element::FIRE, sphere);
  expectedSphere = Sphere({Element::FIRE, Element::FIRE, Element::LIGHTNING});
  
  EXPECT_TRUE(board.getSphere(Element::FIRE).equal(expectedSphere));

}


TEST(Board, CountTest) {
  Board board;
  
  Sphere sphere({Element::FIRE, Element::FIRE, Element::LIGHTNING});
  board.setSphere(Element::FIRE, sphere);
  
  EXPECT_EQ(board.count(Element::FIRE, Element::FIRE), 2);
  EXPECT_EQ(board.count(Element::FIRE, Element::LIGHTNING), 1);
  EXPECT_EQ(board.count(Element::FIRE, Element::ALL), 3);
  EXPECT_EQ(board.count(), 7);
}


TEST(Board, IsMoveValidTest) {
  Board board;
  std::vector<Move> moves;

  moves = {{Element::FIRE, Element::FIRE, Element::WATER}, {Element::EARTH, Element::EARTH, Element::LIGHTNING}, {Element::EARTH, Element::EARTH, Element::LIGHTNING}};
  EXPECT_EQ(board.isMoveValid(moves), false);

  moves = {{Element::FIRE, Element::FIRE, Element::WATER}, {Element::EARTH, Element::EARTH, Element::LIGHTNING}};
  EXPECT_EQ(board.isMoveValid(moves), true);

}


TEST(Board, SourceSpheresHaveLessGemsAndDestSpheresHaveMoreAfterMove) {
  Board board;
  int initSourceCount = board.count(Element::FIRE, Element::ALL);
  int initDestCount = board.count(Element::LIGHTNING, Element::ALL);

  std::vector<Move> move = {{Element::FIRE, Element::FIRE, Element::LIGHTNING}};
  board.doMoves(move);
  
  int finalSourceCount = board.count(Element::FIRE, Element::ALL);
  int finalDestCount = board.count(Element::LIGHTNING, Element::ALL);
  
  EXPECT_GT(initSourceCount, finalSourceCount);
  EXPECT_LT(initDestCount, finalDestCount);
}


TEST(Board, TotalGemsConstantWhenMoving) {
  Board board;
  int initCount = board.count();
  
  std::vector<Move> moves = {{Element::FIRE, Element::FIRE, Element::WATER}, {Element::EARTH, Element::EARTH, Element::LIGHTNING}, {Element::EARTH, Element::EARTH, Element::LIGHTNING}};
  board.doMoves(moves);
  
  int finalCount = board.count();
  
  EXPECT_EQ(initCount, finalCount);
}
