//============================================================================
// Name        : StatusReport.cpp
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================

#include <iostream>
#include <fstream>
#include <gtest/gtest.h>

#include "XMLREADER/XMLReader.h"
#include "Device.h"
#include "Job.h"
#include "StatusReport.h"
#include "SystemProcessing.h"

using namespace std;

class TestXMLReader: public ::testing::Test {
protected:
    friend class XMLReader;
     XMLReader reader;

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

TEST_F(TestXMLReader, TestName) {
    EXPECT_TRUE(reader.getDeviceInfoList().empty());
    reader.readerXML("XMLDataVoorTests/NoName.xml");
    //std::cout << reader.getDeviceInfoList().front().deviceName;
    EXPECT_TRUE(reader.getDeviceInfoList().empty());

    //EXPECT_EQ();
}

TEST_F(TestXMLReader, TestEmissions) {
    EXPECT_TRUE(reader.getDeviceInfoList().empty());
    reader.readerXML("XMLDataVoorTests/NoEmissions.xml");
    //std::cout << reader.getDeviceInfoList().front().deviceName;
    EXPECT_TRUE(reader.getDeviceInfoList().empty());
}

TEST_F(TestXMLReader, TestSpeed) {
    EXPECT_TRUE(reader.getDeviceInfoList().empty());
    reader.readerXML("XMLDataVoorTests/NoSpeed.xml");
    //std::cout << reader.getDeviceInfoList().front().deviceName;
    EXPECT_TRUE(reader.getDeviceInfoList().empty());
}

TEST_F(TestXMLReader, TestJobNumber) {
    EXPECT_TRUE(reader.getJobInfoList().empty());
    reader.readerXML("XMLDataVoorTests/NoJobNumber.xml");
    //std::cout << reader.getDeviceInfoList().front().deviceName;
    EXPECT_TRUE(reader.getJobInfoList().empty());
}

TEST_F(TestXMLReader, TestPageCount) {
    EXPECT_TRUE(reader.getJobInfoList().empty());
    reader.readerXML("XMLDataVoorTests/NoPageCount.xml");
    //std::cout << reader.getDeviceInfoList().front().deviceName;
    EXPECT_TRUE(reader.getJobInfoList().empty());
}

TEST_F(TestXMLReader, TestUserName) {
    EXPECT_TRUE(reader.getJobInfoList().empty());
    reader.readerXML("XMLDataVoorTests/NoUserName.xml");
    //std::cout << reader.getDeviceInfoList().front().deviceName;
    EXPECT_TRUE(reader.getJobInfoList().empty());
}

/*
class EmissionTest: public ::testing::Test {
protected:
    friend class XMLReader;

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

    // XMLReader ttt_;
};

TEST_F(EmissionTest, CheckName) {
    EXPECT_TRUE();
    EXPECT_EQ();
}

class SpeedTest: public ::testing::Test {
protected:
    friend class XMLReader;

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

    // XMLReader ttt_;
};

TEST_F(EmissionTest, CheckName) {
    EXPECT_TRUE();
    EXPECT_EQ();
}
*/

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}