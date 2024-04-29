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
#include "testsMethods.h"
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
    friend class Tests;
    Tests test;
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
    string readFile1(const string& fileName) {
        ifstream file(fileName);
        string content;
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                content += line + "\n";
            }
            file.close();
        }
        return content;
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
    friend class Tests;
    Tests test;
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
    string fileName = "";
    system.redirectIOToFiles(true, true, true, fileName);
    reader.readerXML("XMLDataVoorTests/NoData.xml");
    string actualErrors = readFile("errors.txt");
    string expectedErrors = readFile1("expectedErrors.txt");
    ASSERT_EQ(actualErrors, expectedErrors);
    system.redirectIOToFiles(false, true, true, fileName);
}
TEST_F(OutputComparisonTest, CompareDeviceListOutput) {
    string fileName = "";
    system.redirectIOToFiles(true, true, true, fileName);
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

    system.redirectIOToFiles(false, true, true, fileName);
}
TEST_F(OutputComparisonTest, CompareJobListOutput) {
    // Redirect outputs to files
    string fileName = "";
    system.redirectIOToFiles(true, true, true, fileName);

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
    system.redirectIOToFiles(false, true, true, fileName);
}

// Test case for when the file loads successfully
TEST_F(TestXMLReader, LoadSuccess) {
    string fileName = "";
    system.redirectIOToFiles(true, true, true, fileName);
    bool result = reader.readerXML("TestLoadSuccess.xml");
    EXPECT_FALSE(result);
    system.redirectIOToFiles(false, true, true, fileName);
}

// Test case for when the file fails to load or does not exist
TEST_F(TestXMLReader, LoadFail) {
    string fileName = "";
    system.redirectIOToFiles(true, true, true, fileName);
    bool result = reader.readerXML("TestFileDoesNotExist.xml");
    EXPECT_FALSE(result);
    system.redirectIOToFiles(false, true, true, fileName);
}

TEST_F(TestXMLReader, TestName) {
    string fileName = "";
    system.redirectIOToFiles(true, true, true, fileName);
    reader.readerXML("XMLDataVoorTests/NoName.xml");
    string actualErrors = readFile("errors.txt");
    string expectedErrors = readFile("NoNameDeviceerrors.txt");
    ASSERT_EQ(actualErrors, expectedErrors);
    system.redirectIOToFiles(false, true, true, fileName);
}

TEST_F(TestXMLReader, TestEmissions) {
    string fileName = "";
    system.redirectIOToFiles(true, true, true, fileName);
    reader.readerXML("XMLDataVoorTests/NoEmissions.xml");
    string actualErrors = readFile("errors.txt");
    string expectedErrors = readFile("NoEmissionserrors.txt");
    ASSERT_EQ(actualErrors, expectedErrors);
    system.redirectIOToFiles(false, true, true, fileName);
}
TEST_F(TestXMLReader, TestDeviceType) {
    string fileName = "";
    system.redirectIOToFiles(true, true, true, fileName);
    reader.readerXML("XMLDataVoorTests/NoTypeDevice.xml");
    string actualErrors = readFile("errors.txt");
    string expectedErrors = readFile("NoDeviceTypeerrors.txt");
    ASSERT_EQ(actualErrors, expectedErrors);
    system.redirectIOToFiles(false, true, true, fileName);
}
TEST_F(TestXMLReader, TestSpeed) {
    string fileName = "";
    system.redirectIOToFiles(true, true, true, fileName);
    reader.readerXML("XMLDataVoorTests/NoSpeed.xml");
    string actualErrors = readFile("errors.txt");
    string expectedErrors = readFile("NoSpeederrors.txt");
    ASSERT_EQ(actualErrors, expectedErrors);
    system.redirectIOToFiles(false, true, true, fileName);
}
TEST_F(TestXMLReader, TestCost) {
    string fileName = "";
    system.redirectIOToFiles(true, true, true, fileName);
    reader.readerXML("XMLDataVoorTests/NoCost.xml");
    string actualErrors = readFile("errors.txt");
    string expectedErrors = readFile("NoCosterrors.txt");
    ASSERT_EQ(actualErrors, expectedErrors);
    system.redirectIOToFiles(false, true, true, fileName);
}
TEST_F(TestXMLReader, TestJobNumber) {
    string fileName = "";
    system.redirectIOToFiles(true, true, true, fileName);
    reader.readerXML("XMLDataVoorTests/NoJobNumber.xml");
    string actualErrors = readFile("errors.txt");
    string expectedErrors = readFile("NoJobNumbererrors.txt");
    ASSERT_EQ(actualErrors, expectedErrors);
    system.redirectIOToFiles(false, true, true, fileName);
}

TEST_F(TestXMLReader, TestPageCount) {
    string fileName = "";
    system.redirectIOToFiles(true, true, true, fileName);
    reader.readerXML("XMLDataVoorTests/noPageCount.xml");
    string actualErrors = readFile("errors.txt");
    string expectedErrors = readFile("NoPageCounterrors.txt");
    ASSERT_EQ(actualErrors, expectedErrors);
    system.redirectIOToFiles(false, true, true, fileName);
}

TEST_F(TestXMLReader, TestJobType) {
    string fileName = "";
    system.redirectIOToFiles(true, true, true, fileName);
    reader.readerXML("XMLDataVoorTests/NoJobType.xml");
    string actualErrors = readFile("errors.txt");
    string expectedErrors = readFile("NoJobTypeerrors.txt");
    ASSERT_EQ(actualErrors, expectedErrors);
    system.redirectIOToFiles(false, true, true, fileName);
}
TEST_F(TestXMLReader, TestUserName) {
    string fileName = "";
    system.redirectIOToFiles(true, true, true, fileName);
    reader.readerXML("XMLDataVoorTests/NoUserName.xml");
    string actualErrors = readFile("errors.txt");
    string expectedErrors = readFile("NoUsererrors.txt");
    ASSERT_EQ(actualErrors, expectedErrors);
    system.redirectIOToFiles(false, true, true, fileName);
}

TEST_F(TestXMLReader, TestSuccessfulParse) {
    string fileName = "";
    system.redirectIOToFiles(true, true, true, fileName);
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
    system.redirectIOToFiles(false, true, true, fileName);
    //
}
TEST_F(TestXMLReader, TestManualProcess) {
    string fileName = "";
    system.redirectIOToFiles(true, true, true, fileName);
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
    system.redirectIOToFiles(false, true, true, fileName);
}

TEST_F(TestXMLReader, TestAutomatedProcess) {
    string fileName = "";
    system.redirectIOToFiles(true, true, true, fileName);
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
    system.redirectIOToFiles(false, true, true, fileName);
}

TEST_F(TestXMLReader, TestStatusReport) {
    string fileName = "";
    system.redirectIOToFiles(true, true, true, fileName);
    reader.readerXML("XMLDataVoorTests/NoDAta.xml");
    const vector<Device> NoDataDevices = device.populateFromXMLReader(reader);
    const vector<Job> NoDataJobs = job.populateFromXMLReader(reader);
    reader.readerXML("XMLDataVoorTests/ValidDAta.xml");
    vector<Device> WithDataDevices = device.populateFromXMLReader(reader);
    vector<Job> WithDataJobs = job.populateFromXMLReader(reader);

    bool noData = status.generateStatusReport(NoDataJobs);
    EXPECT_TRUE(noData);
    bool withData = status.generateStatusReport(WithDataJobs );
    EXPECT_TRUE(withData);
    system.redirectIOToFiles(false, true, true, fileName);
}

// happy day test
// lege file test


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}