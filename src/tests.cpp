#include "gtest/gtest.h"

#include "Largest.h"

using namespace std;

class LargestTest: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }
};

TEST_F(LargestTest, SimpleTest) {
    std::vector<int> some_numbers = std::vector<int>();
    some_numbers.push_back(3);
    some_numbers.push_back(5);
    some_numbers.push_back(-11);

    int max = largest2(&some_numbers);

    EXPECT_EQ(5, max);
}


TEST_F(LargestTest, SingleElementTest){
    std::vector<int> singleElement = {5};
    int max = largest2(&singleElement);
    EXPECT_EQ(static_cast<std::size_t>(1), singleElement.size());
    EXPECT_EQ(5, max);
}

TEST_F(LargestTest, NoElementTest){
    vector<int> noElement={};
    int max=
}


#include "Fighterplane.h"



class FighterplaneTest: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }

};


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
