//
// Created by koech on 7/6/2023.
//

#ifndef C_EMV_DATA_ELEMENT_H
#define C_EMV_DATA_ELEMENT_H

#include <stdio.h>

typedef enum {
    BYTES = 1,
    ASCII = 2,
    DOL = 3,
    DEC = 4,
    DATE = 5,
    INT = 6,
    COUNTRY = 7,
    CURRENCY = 8,
    TAG_LIST = 9,
    ASRPD = 10,
    CVM_LIST = 11,
    AUC = 12
} Parse;

typedef struct {
    unsigned char first;
    unsigned char second;
} Pair_tag;

typedef struct {
    Pair_tag tag;
    const char* description;
    Parse parse;
    const char* shortname;
} Element;

Element  ELEMENT_TABLE[] = {
        {{0x42, 0x00}, "Issuer Identification Number", BYTES, "IIN"},
        {{0x46, 0x00}, "Pre-issuing data", BYTES, NULL},
        {{0x4F, 0x00} , "Application Dedicated File {ADF} Name", BYTES, "ADF_NAME"},
        {{0x50, 0x00}, "Application Label", ASCII, "APP_LABEL"},
        {{0x57, 0x00}, "Track 2 Equivalent Data", BYTES, "TRACK2"},
        {{0x5A, 0x00}, "Application Primary Account Number {PAN}", DEC, "PAN"},
        {{0x5E, 0x00}, "Proprietary Login Data", BYTES, NULL},
        {{0x5F, 0x20}, "Cardholder Name", ASCII, NULL},
        {{0x5F, 0x24}, "Application Expiration Date", DATE, NULL},
        {{0x5F, 0x25}, "Application Effective Date", DATE, NULL},
        {{0x5F, 0x28}, "Issuer Country Code", COUNTRY, NULL},
        {{0x5F, 0x2A}, "Transaction Country Code", COUNTRY, NULL},
        {{0x5F, 0x2D}, "Language Preference", ASCII, NULL},
        {{0x5F, 0x30}, "Service Code", BYTES, NULL},
        {
                {0x5F, 0x34},
                        "Application Primary Account Number {PAN} Sequence Number",
                        INT,
                        "PAN_SN",
        },
        {{0x5F, 0x36}, "Transaction Currency Exponent", BYTES, NULL},
        {{0x5F, 0x50}, "Issuer URL", ASCII, NULL},
        {{0x5F, 0x53}, "International Bank Account Number {IBAN}", BYTES, "IBAN"},
        {{0x5F, 0x54}, "Bank Identifier Code {BIC}", BYTES, "BIC"},
        {{0x5F, 0x55}, "Issuer Country Code {alpha2 format}", ASCII, NULL},
        {{0x5F, 0x56}, "Issuer Country Code {alpha3 format}", ASCII, NULL},
        {{0x5F, 0x57}, "Account Type", BYTES, NULL},
        {{0x61, 0x00}, "Application Template", BYTES, "APP"},
        {{0x6F, 0x00}, "FCI Template", BYTES, "FCI"},
        {{0x70, 0x00}, "Read Record Response Template", BYTES, "RECORD"},
        {{0x71, 0x00}, "Issuer Script Template 1", BYTES, NULL},
        {{0x72, 0x00}, "Issuer Script Template 2", BYTES, NULL},
        {{0x73, 0x00}, "Directory Discretionary Template", BYTES, NULL},
        {{0x77, 0x00}, "Response Template Format 2", BYTES, "RMTF2"},
        {{0x80, 0x00}, "Response Template Format 1", BYTES, "RMTF1"},
        {{0x81, 0x00}, "Amount, Authorised {Binary}", BYTES, NULL},
        {{0x82, 0x00}, "Application Interchange Profile", BYTES, NULL},
        {{0x83, 0x00}, "Command Template", BYTES, NULL},
        {{0x84, 0x00}, "Dedicated File {DF} Name", BYTES, "DF"},
        {{0x86, 0x00}, "Issuer Script Command", BYTES, NULL},
        {{0x87, 0x00}, "Application Priority Indicator", INT, NULL},
        {{0x88, 0x00}, "Short File Identifier", BYTES, "SFI"},
        {{0x89, 0x00}, "Authorisation Code", BYTES, NULL},
        {{0x8A,0x00}, "Authorisation Response Code", BYTES, NULL},
        {{0x8C, 0x00}, "Card Risk Management Data Object List 1 {CDOL1}", DOL, "CDOL1"},
        {{0x8D, 0x00}, "Card Risk Management Data Object List 2 {CDOL2}", DOL, "CDOL2"},
        {{0x8E, 0x00}, "Cardholder Verification Method {CVM} List", CVM_LIST, NULL},
        {{0x8F, 0x00}, "Certification Authority Public Key Index", BYTES, NULL},
        {{0x90, 0x00}, "Issuer Public Key Certificate", BYTES, NULL},
        {{0x91, 0x00}, "Issuer Authentication Data", BYTES, NULL},
        {{0x92, 0x00}, "Issuer Public Key Remainder", BYTES, NULL},
        {{0x93, 0x00}, "Signed Static Application Data", BYTES, NULL},
        {{0x94, 0x00}, "Application File Locator", BYTES, "AFL"},
        {{0x95, 0x00}, "Terminal Verification Results", BYTES, NULL},
        {{0x97, 0x00}, "Transaction Certificate Data Object List {TDOL}", DOL, "TDOL"},
        {{0x98, 0x00}, "Transaction Certificate {TC} Hash Value", BYTES, NULL},
        {{0x99, 0x00}, "Transaction Personal Identification Number {PIN} Data", BYTES, NULL},
        {{0x9A, 0x00}, "Transaction Date", DATE, NULL},
        {{0x9B, 0x00}, "Transaction Status Information", BYTES, NULL},
        {{0x9C, 0x00}, "Transaction Type", BYTES, NULL},
        {{0x9D, 0x00}, "DDF Name", BYTES, "DDF"},
        {{0xC8, 0x00}, "Card risk management country code", COUNTRY, NULL},
        {{0xC9, 0x00}, "Card risk management currency code", CURRENCY, NULL},
        {{0x9F, 0x01}, "Acquirer Identifier", BYTES, NULL},
        {{0x9F, 0x02}, "Amount, Authorised", BYTES, NULL},
        {{0x9F, 0x03}, "Amount, Other {Numeric}", BYTES, NULL},
        {{0x9F, 0x04}, "Amount, Other {Binary}", BYTES, NULL},
        {{0x9F, 0x05}, "Application Discretionary Data", BYTES, NULL},
        {{0x9F, 0x06}, "Application Identifier {AID} - terminal", BYTES, NULL},
        {{0x9F, 0x07}, "Application Usage Control", AUC, "AUC"},
        {{0x9F, 0x08}, "Application Version Number", BYTES, NULL},
        {{0x9F, 0x09}, "Application Version Number", BYTES, NULL},
        {
                {0x9F, 0x0A},
                        "Application Selection Registered Proprietary Data",
                        ASRPD,
                        NULL,
        },
        {{0x9F, 0x0B}, "Cardholder Name Extended", ASCII, NULL},
        {{0x9F, 0x0D}, "Issuer Action Code - Default", BYTES, NULL},
        {{0x9F, 0x0E}, "Issuer Action Code - Denial", BYTES, NULL},
        {{0x9F, 0x0F}, "Issuer Action Code - Online", BYTES, NULL},
        {{0x9F, 0x10}, "Issuer Application Data", BYTES, NULL},
        {{0x9F, 0x11}, "Issuer Code Table Index", BYTES, NULL},
        {{0x9F, 0x12}, "Application Preferred Name", ASCII, NULL},
        {
                {0x9F, 0x13},
                "Last Online Application Transaction Counter {ATC} Register",
                INT,
                NULL,
        },
        {{0x9F, 0x14}, "Lower Consecutive Offline Limit", BYTES, NULL},
        {{0x9F, 0x15}, "Merchant Category Code", BYTES, NULL},
        {{0x9F, 0x16}, "Merchant Identifier", BYTES, NULL},
        {{0x9F, 0x17}, "PIN Try Counter", INT, NULL},
        {{0x9F, 0x18}, "Issuer Script Identifier", BYTES, NULL},
        {{0x9F, 0x1A}, "Terminal Country Code", COUNTRY, NULL},
        {{0x9F, 0x1B}, "Terminal Floor Limit", BYTES, NULL},
        {{0x9F, 0x1C}, "Terminal Identification", BYTES, NULL},
        {{0x9F, 0x1D}, "Terminal Risk Management Data", BYTES, NULL},
        {{0x9F, 0x1E}, "Interface Device {IFD} Serial Number", BYTES, NULL},
        {{0x9F, 0x1F}, "Track 1 Discretionary Data", BYTES, NULL},
        {{0x9F, 0x20}, "Track 2 Discretionary Data", BYTES, NULL},
        {{0x9F, 0x21}, "Transaction Time", BYTES, NULL},
        {{0x9F, 0x22}, "Certification Authority Public Key Index", BYTES, NULL},
        {{0x9F, 0x23}, "Upper Consecutive Offline Limit", BYTES, NULL},
        {{0x9F, 0x26}, "Application Cryptogram", BYTES, NULL},
        {{0x9F, 0x27}, "Cryptogram Information Data", BYTES, NULL},
        {{0x9F, 0x2D}, "ICC PIN Encipherment Public Key Certificate", BYTES, NULL},
        {{0x9F, 0x2E}, "ICC PIN Encipherment Public Key Exponent", BYTES, NULL},
        {{0x9F, 0x2F}, "ICC PIN Encipherment Public Key Remainder", BYTES, NULL},
        {{0x9F, 0x32}, "Issuer Public Key Exponent", BYTES, NULL},
        {{0x9F, 0x33}, "Terminal Capabilities", BYTES, NULL},
        {{0x9F, 0x34}, "Cardholder Verification Method {CVM} Results", BYTES, NULL},
        {{0x9F, 0x35}, "Terminal Type", BYTES, NULL},
        {{0x9F, 0x36}, "Application Transaction Counter", INT, "ATC"},
        {{0x9F, 0x37}, "Unpredictable Number", BYTES, NULL},
        {{0x9F, 0x38}, "Processing Options Data Object List {PDOL}", DOL, "PDOL"},
        {{0x9F, 0x39}, "Point-of-Service {POS} Entry Mode", BYTES, NULL},
        {{0x9F, 0x3A}, "Amount, Reference Currency", BYTES, NULL},
        {{0x9F, 0x3B}, "Application Reference Currency", BYTES, NULL},
        {{0x9F, 0x3C}, "Transaction Reference Currency Code", BYTES, NULL},
        {{0x9F, 0x3D}, "Transaction Reference Currency Exponent", BYTES, NULL},
        {{0x9F, 0x40}, "Additional Terminal Capabilities", BYTES, NULL},
        {{0x9F, 0x41}, "Transaction Sequence Counter", BYTES, NULL},
        {{0x9F, 0x42}, "Application Currency Code", CURRENCY, NULL},
        {{0x9F, 0x43}, "Application Reference Currency Exponent", BYTES, NULL},
        {{0x9F, 0x44}, "Application Currency Exponent", INT, NULL},
        {{0x9F, 0x45}, "Data Authentication Code", BYTES, NULL},
        {{0x9F, 0x46}, "ICC Public Key Certificate", BYTES, NULL},
        {{0x9F, 0x47}, "ICC Public Key Exponent", BYTES, NULL},
        {{0x9F, 0x48}, "ICC Public Key Remainder", BYTES, NULL},
        {
                {0x9F, 0x49},
                        "Dynamic Data Authentication Data Object List {DDOL}",
                        DOL,
                        "DDOL",
        },
        {{0x9F, 0x4A}, "Static Data Authentication Tag List", TAG_LIST, NULL},
        {{0x9F, 0x4B}, "Signed Dynamic Application Data", BYTES, NULL},
        {{0x9F, 0x4C}, "ICC Dynamic Number", BYTES, NULL},
        {{0x9F, 0x4D}, "Log Entry", BYTES, NULL},
        {{0x9F, 0x4E}, "Merchant Name and Location", BYTES, NULL},
        {{0x9F, 0x4F}, "Log Format", BYTES, NULL},
        {{0x9F, 0x55}, "Issuer Authentication Flags", BYTES, "IAF"},
        {{0x9F, 0x56}, "Issuer Proprietary Bitmap", BYTES, "IPB"},
        {
                {0x9F, 0x5C},
                        "Cumulative Total Transaction Amount Upper Limit",
                        INT,
                        "CTTAUL",
        },
        {{0x9F, 0x5D}, "Available Offline Spending Amount", INT, "AOSA"},
        {
                {0x9F, 0x5E},
                        "Consecutive Transaction International Upper Limit",
                        INT,
                        "CTIUL",
        },
        {{0x9F, 0x6E}, "Third Party Data", BYTES, NULL},
        {{0xA5, 0X00}, "FCI Proprietary Template", BYTES, "FCI_PROP"},
        {{0xBF, 0x0C}, "FCI Issuer Discretionary Data", BYTES, NULL},
};


#endif //C_EMV_DATA_ELEMENT_H
