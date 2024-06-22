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
    std::string readFile(const std::string& fileName) {
        std::ifstream file(fileName);
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }
    friend class XMLReader;
    XMLReader reader;

    friend class System;
    System system;

    friend class Device;
    Device device;
    friend class Job;
    Job job;
    friend class StatusReport;
    StatusReport status;
    //friend class StatusReport;
    //StatusReport report;

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
    string readFile(const std::string& fileName) {
        ifstream file(fileName);
        stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }
    friend class XMLReader;
    XMLReader reader;

    friend class System;
    System system;

    friend class Device;
    Device device;
    friend class Job;
    Job job;
    friend class StatusReport;
    StatusReport status;

    // Perform any setup needed before each test
    virtual void SetUp() override {
        // Redirect outputs to files, run functions that generate outputs, etc.
    }

    // Clean up after each test
    virtual void TearDown() override {
        // Optionally, delete files if needed, or restore states if needed
    }
};
/*
TEST_F(OutputComparisonTest, CompareOutputs) {
    system.redirectIOToFiles(true, true, true);
    reader.readerXML("XMLDataVoorTests/NoData.xml");
    vector<Device> deviceList = device.populateFromXMLReader(reader);
    vector<Job> jobList = job.populateFromXMLReader(reader);
    device.printDeviceList(deviceList);
    job.printJobList(jobList);
    string actualErrors = readFile("errors.txt");
    string expectedErrors = readFile("expectedErrors.txt");
    ASSERT_EQ(actualErrors, expectedErrors);
    system.redirectIOToFiles(false, true, true);
}
*/
TEST_F(OutputComparisonTest, CompareDeviceListOutput) {
    system.redirectIOToFiles(true, true, true);
    reader.readerXML("XMLDataVoorTests/ValidData.xml");
    vector<Device> deviceList = device.populateFromXMLReader(reader);
    device.printDeviceList(deviceList);
    string deviceListOutputFileName = "expectedDeviceListOutput.txt";
    device.writeDeviceInfoOutputToFile(deviceList, deviceListOutputFileName);
    // Read actual job list output
    string actualOutput = readFile("output.txt");
    // Read expected job list output
    string expectedOutput = readFile("expectedDeviceListOutput.txt");

    ASSERT_EQ(actualOutput, expectedOutput);

    system.redirectIOToFiles(false, true, true);
}
TEST_F(OutputComparisonTest, CompareJobListOutput) {
    // Redirect outputs to files
    system.redirectIOToFiles(true, true, false);

    // Read XML file and populate job list
    reader.readerXML("XMLDataVoorTests/ValidData.xml");
    vector<Job> jobList = job.populateFromXMLReader(reader);
    // Print job list
    job.printJobList(jobList);
    string jobListOutputFileName = "expectedJobListOutput.txt";
    job.writeJobListOutputToFile(jobList, jobListOutputFileName);
    // Read actual job list output
    string actualOutput = readFile("output.txt");

    // Read expected job list output
    string expectedOutput = readFile("expectedJobListOutput.txt");

    // Compare actual and expected job list outputs
    ASSERT_EQ(actualOutput, expectedOutput);
}
// Test case for when the file loads successfully
TEST_F(TestXMLReader, LoadSuccess) {
    system.redirectIOToFiles(true, true, true);
    bool result = reader.readerXML("TestLoadSuccess.xml");
    EXPECT_FALSE(result);
    system.redirectIOToFiles(false, true, true);
}

// Test case for when the file fails to load or does not exist
TEST_F(TestXMLReader, LoadFail) {
    system.redirectIOToFiles(true, true, true);
    bool result = reader.readerXML("TestFileDoesNotExist.xml");
    EXPECT_FALSE(result);
    system.redirectIOToFiles(false, true, true);
}

TEST_F(TestXMLReader, TestName) {
    system.redirectIOToFiles(true, true, true);
    EXPECT_TRUE(reader.getDeviceInfoList().empty());
    reader.readerXML("XMLDataVoorTests/NoName.xml");

    // Read actual error output
    string actualErrors = readFile("errors.txt");
    // Read expected error output
    string expectedError = readFile("expectedErrors/noNameExpected.txt");
    ASSERT_EQ(actualErrors, expectedError);

    system.redirectIOToFiles(false, true, true);
}

TEST_F(TestXMLReader, TestEmissions) {
    system.redirectIOToFiles(true, true, true);
    EXPECT_TRUE(reader.getDeviceInfoList().empty());
    reader.readerXML("XMLDataVoorTests/NoEmissions.xml");
    string actualErrors = readFile("errors.txt");
    string expectedError = readFile("expectedErrors/noEmissionsExpected.txt");
    ASSERT_EQ(actualErrors, expectedError);

    system.redirectIOToFiles(false, true, true);
}

TEST_F(TestXMLReader, TestSpeed) {
    system.redirectIOToFiles(true, true, true);
    EXPECT_TRUE(reader.getDeviceInfoList().empty());
    reader.readerXML("XMLDataVoorTests/NoSpeed.xml");

    //EXPECT_TRUE(!actualErrors.empty());
    //EXPECT_TRUE(reader.getDeviceInfoList().empty());

    string actualErrors = readFile("errors.txt");
    string expectedError = readFile("expectedErrors/noSpeedExpected.txt");
    ASSERT_EQ(actualErrors, expectedError);

    system.redirectIOToFiles(false, true, true);
}

TEST_F(TestXMLReader, TestJobNumber) {
    system.redirectIOToFiles(true, true, true);
    EXPECT_TRUE(reader.getJobInfoList().empty());
    reader.readerXML("XMLDataVoorTests/NoJobNumber.xml");

    //EXPECT_TRUE(!actualErrors.empty());
    //EXPECT_TRUE(reader.getJobInfoList().empty());

    string actualErrors = readFile("errors.txt");
    string expectedError = readFile("expectedErrors/noJobNumberExpected.txt");
    ASSERT_EQ(actualErrors, expectedError);
    system.redirectIOToFiles(false, true, true);
}

TEST_F(TestXMLReader, TestPageCount) {
    system.redirectIOToFiles(true, true, true);
    EXPECT_TRUE(reader.getJobInfoList().empty());
    reader.readerXML("XMLDataVoorTests/noPageCount.XML");

    //EXPECT_TRUE(!actualErrors.empty());
    //EXPECT_TRUE(reader.getJobInfoList().empty());

    string actualErrors = readFile("errors.txt");
    string expectedError = readFile("expectedErrors/noPageCountExpected.txt");
    ASSERT_EQ(actualErrors, expectedError);
    system.redirectIOToFiles(false, true, true);
}

TEST_F(TestXMLReader, TestUserName) {
    system.redirectIOToFiles(true, true, true);
    EXPECT_TRUE(reader.getJobInfoList().empty());
    reader.readerXML("XMLDataVoorTests/NoUserName.xml");

    //EXPECT_TRUE(!actualErrors.empty());
    //EXPECT_TRUE(reader.getJobInfoList().empty());

    string actualErrors = readFile("errors.txt");
    string expectedError = readFile("expectedErrors/noUserNameExpected.txt");
    ASSERT_EQ(actualErrors, expectedError);
    system.redirectIOToFiles(false, true, true);
}

TEST_F(TestXMLReader, TestSuccessfulParse) {
    system.redirectIOToFiles(true, true, true);
    reader.readerXML("XMLDataVoorTests/ValidData.xml");
    string actualErrors = readFile("errors.txt");
    EXPECT_TRUE(actualErrors.empty());
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
    EXPECT_EQ(deviceInfoList.front().deviceName, "Office_Printer5");
    EXPECT_EQ(deviceInfoList.front().emissions, 3);
    EXPECT_EQ(deviceInfoList.front().speed, 40);

    // Controlleren of de grootte van jobInfoList = 2, wat zou betekenen dat er inderdaad 2 jobs zijn ingelezen.
    ASSERT_EQ(jobInfoList.size(), expectedJobs);

    // deviceName, emmisions & speed van het eerste Device checken
    EXPECT_EQ(jobInfoList.front().jobNumber, 1);
    EXPECT_EQ(jobInfoList.front().pageCount, 1);
    EXPECT_EQ(jobInfoList.front().userName, "anonymous_user1");
    system.redirectIOToFiles(false, true, true);
    //
}
TEST_F(TestXMLReader, TestManualProcess) {
    system.redirectIOToFiles(true, true, true);
    reader.readerXML("XMLDataVoorTests/testManualProcess.xml");
    vector<Device> tempDevices = device.populateFromXMLReader(reader);
    vector<Job> tempJobs = job.populateFromXMLReader(reader);
    size_t jobExpected = 1;
    string deviceName = "Office_Printer5";
    int jobNumber = 1;
    bool result = false;
    if (!tempDevices.empty()) {
        result = system.schedulerManual(deviceName, jobNumber, tempJobs);
    }
    ASSERT_EQ(tempJobs.size(), jobExpected);
    EXPECT_TRUE(result);
    system.redirectIOToFiles(false, true, true);
}

TEST_F(TestXMLReader, TestAutomatedProcess) {
    system.redirectIOToFiles(true, true, true);
    reader.readerXML("XMLDataVoorTests/testAutomatedProcess.xml");
    vector<Device> tempDevices = device.populateFromXMLReader(reader);
    vector<Job> tempJobs = job.populateFromXMLReader(reader);
    size_t jobCurrent = 18;
    ASSERT_EQ(tempJobs.size(), jobCurrent);

    bool result = false;
    if (!tempDevices.empty()) {
        result = system.schedulerAutomated(tempDevices, tempJobs);
    }
    ASSERT_NE(tempJobs.size(), jobCurrent);
    EXPECT_TRUE(result);
    system.redirectIOToFiles(false, true, true);
}

// TEST_F(TestXMLReader, TestStatusReport) {
//     system.redirectIOToFiles(true, true, true);
//     reader.readerXML("XMLDataVoorTests/NoDAta.xml");
//     const vector<Device> NoDataDevices = device.populateFromXMLReader(reader);
//     const vector<Job> NoDataJobs = job.populateFromXMLReader(reader);
//     reader.readerXML("XMLDataVoorTests/ValidDAta.xml");
//     vector<Device> WithDataDevices = device.populateFromXMLReader(reader);
//     vector<Job> WithDataJobs = job.populateFromXMLReader(reader);
//
//     bool noData = status.generateStatusReport(NoDataJobs);
//     EXPECT_TRUE(noData);
//     bool withData = status.generateStatusReport(WithDataJobs );
//     EXPECT_TRUE(withData);
//     system.redirectIOToFiles(false, true, true);
// }

// happy day test
// lege file test


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}