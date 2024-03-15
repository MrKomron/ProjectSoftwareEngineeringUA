//============================================================================
// Name        : Tests.cpp
// Author      : Soliman Blanco, Oubayy Ahale, Komronjon Vosidov
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Soliman Blanco, Oubayy Ahale, Komronjon Vosidov - University of Antwerp
// Description : This code tests various things
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

TEST_F(TestXMLReader, TestSuccessfulParse) {
    reader.readerXML("XMLDataVoorTests/ValidData.xml");
    auto deviceInfoList = reader.getDeviceInfoList();
    auto jobInfoList = reader.getJobInfoList();

    // We nemen aan dat ValidData.XML precies 2 devices en 2 jobs bevat.
    // getDeviceInfoList() en getJobInfoList() retourneren de lijsten met device- en jobinformatie die door de XMLReader zijn ingelezen en verwerkt.

    // consistent typegebruik fixen
    size_t expectedDevices = 2;
    size_t expectedJobs = 2;

    // Controlleren of de grootte van jobInfoList = 2, wat zou betekenen dat er inderdaad 2 devices zijn ingelezen.
    ASSERT_EQ(deviceInfoList.size(), expectedDevices);

    // Controlleren of de grootte van jobInfoList = 2, wat zou betekenen dat er inderdaad 2 jobs zijn ingelezen.
    ASSERT_EQ(jobInfoList.size(), expectedJobs);
}



int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}