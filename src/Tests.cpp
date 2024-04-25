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
#include <sstream>
#include <string>
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

    friend class System;
     System system;
    friend class Device;
     Device device;
    friend class Job;
     Job job;
    friend class StatusReport;
     StatusReport report;

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

class OutputComparisonTest : public ::testing::Test {
protected:
    // Helper function to read file content into a string
    std::string readFile(const std::string& fileName) {
        std::ifstream file(fileName);
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    // Perform any setup needed before each test
    virtual void SetUp() override {
        // Redirect outputs to files, run functions that generate outputs, etc.
    }

    // Clean up after each test
    virtual void TearDown() override {
        // Optionally, delete files if needed, or restore states if needed
    }
};

TEST_F(OutputComparisonTest, CompareOutputs) {
    string actualOutput = readFile("output.txt");
    string expectedOutput = readFile("expectedOutput.txt");
    ASSERT_EQ(actualOutput, expectedOutput);

    string actualErrors = readFile("errors.txt");
    string expectedErrors = readFile("expectedErrors.txt");
    ASSERT_EQ(actualErrors, expectedErrors);
}

// Test case for when the file loads successfully
TEST_F(TestXMLReader, LoadSuccess) {
    bool result = reader.readerXML("TestLoadSuccess.xml");
    EXPECT_FALSE(result);
}

// Test case for when the file fails to load or does not exist
TEST_F(TestXMLReader, LoadFail) {
    bool result = reader.readerXML("TestFileDoesNotExist.xml");
    EXPECT_FALSE(result);
}

TEST_F(TestXMLReader, TestName) {
    EXPECT_TRUE(reader.getDeviceInfoList().empty());
    reader.readerXML("XMLDataVoorTests/NoName.xml");
    //cout << reader.getDeviceInfoList().front().deviceName;
    EXPECT_TRUE(reader.getDeviceInfoList().empty());
}

TEST_F(TestXMLReader, TestEmissions) {
    EXPECT_TRUE(reader.getDeviceInfoList().empty());
    reader.readerXML("XMLDataVoorTests/NoEmissions.xml");
    //cout << reader.getDeviceInfoList().front().deviceName;
    EXPECT_TRUE(reader.getDeviceInfoList().empty());
}

TEST_F(TestXMLReader, TestSpeed) {
    EXPECT_TRUE(reader.getDeviceInfoList().empty());
    reader.readerXML("XMLDataVoorTests/NoSpeed.xml");
    //cout << reader.getDeviceInfoList().front().deviceName;
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

    // Controlleren of de grootte van deviceInfoList = 2, wat zou betekenen dat er inderdaad 2 devices zijn ingelezen.
    ASSERT_EQ(deviceInfoList.size(), expectedDevices);

    // deviceName, emmisions & speed van het eerste Device checken
    EXPECT_EQ(deviceInfoList.front().deviceName, "Office_Printer1");
    EXPECT_EQ(deviceInfoList.front().emissions, 1);
    EXPECT_EQ(deviceInfoList.front().speed, 10);

    // Controlleren of de grootte van jobInfoList = 2, wat zou betekenen dat er inderdaad 2 jobs zijn ingelezen.
    ASSERT_EQ(jobInfoList.size(), expectedJobs);

    // deviceName, emmisions & speed van het eerste Device checken
    EXPECT_EQ(jobInfoList.front().jobNumber, 1111);
    EXPECT_EQ(jobInfoList.front().pageCount, 1);
    EXPECT_EQ(jobInfoList.front().userName, "MelonMan");

    //
}

TEST_F(TestXMLReader, TestManualProcess) {
    reader.readerXML("XMLDataVoorTests/testManualProcess.xml");
    vector<Device> tempDevices = device.populateFromXMLReader(reader);
    vector<Job> tempJobs = job.populateFromXMLReader(reader);
    size_t jobExpected = 0;

    bool result = false;
    if (!tempDevices.empty()) {
        result = system.manualProcess(tempDevices, tempJobs);
    }

    ASSERT_EQ(tempJobs.size(), jobExpected);
    EXPECT_TRUE(result);
}

TEST_F(TestXMLReader, TestAutomatedProcess) {
    reader.readerXML("XMLDataVoorTests/testAutomatedProcess.xml");
    vector<Device> tempDevices = device.populateFromXMLReader(reader);
    vector<Job> tempJobs = job.populateFromXMLReader(reader);
    size_t jobCurrent = 2;
    ASSERT_EQ(tempJobs.size(), jobCurrent);

    bool result = false;
    if (!tempDevices.empty()) {
        result = system.automatedProcess(tempDevices, tempJobs);
    }
    ASSERT_NE(tempJobs.size(), jobCurrent);
    EXPECT_TRUE(result);

}

TEST_F(TestXMLReader, TestStatusReport) {
    reader.readerXML("XMLDataVoorTests/NoDAta.xml");
    const vector<Device> NoDataDevices = device.populateFromXMLReader(reader);
    const vector<Job> NoDataJobs = job.populateFromXMLReader(reader);
   reader.readerXML("XMLDataVoorTests/ValidDAta.xml");
    vector<Device> WithDataDevices = device.populateFromXMLReader(reader);
    vector<Job> WithDataJobs = job.populateFromXMLReader(reader);

    bool noData = report.generateStatusReport(NoDataDevices, NoDataJobs );
    EXPECT_FALSE(noData);
    bool withData = report.generateStatusReport(WithDataDevices, WithDataJobs );
    EXPECT_TRUE(withData);
}


// happy day test
// lege file test


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}