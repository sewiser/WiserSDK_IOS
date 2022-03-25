//
// WiserSmartBaseKitErrors.h
// WiserSmartBaseKit
//
// Copyright (c) 2014-2021 Wiser Inc. (https://developer.wiser.com)

#ifndef WiserSmartBaseKitErrors_h
#define WiserSmartBaseKitErrors_h

/*
 *  WSBaseKitError
 *
 *  Discussion:
 *    Error returned as code to NSError from WiserSmartBaseKit.
 */

extern NSString *const kWSBaseKitErrorDomain;

typedef NS_ENUM(NSInteger, WSBaseKitError) {
    /// Request Error.
    kWSBaseKitErrorAPIRequestError                       = 2000,
    /// Return data type is illegal.
    kWSBaseKitErrorAPIResponseDataTypeIllegal            = 2001,
    /// The returned data sign is inconsistent.
    kWSBaseKitErrorAPIResponseDataSignInconsistent       = 2002,
    /// Return data decode error.
    kWSBaseKitErrorAPIResponseDataDecodeError            = 2003,
    /// Network Error.
    kWSBaseKitErrorNetworkError                          = 2004,
    
};

#endif /* WiserSmartBaseKitErrors_h */
