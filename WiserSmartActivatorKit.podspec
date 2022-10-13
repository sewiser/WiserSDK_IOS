Pod::Spec.new do |s|
  s.name = "WiserSmartActivatorKit"
  s.version = "3.26.6"
  s.summary = "A short description of #{s.name}."
  s.license = {"type"=>"MIT"}
  s.authors = {"0x5e"=>"gaosen.wiser.com"}
  s.homepage = "https:/.wiser.com"
  s.source = { :http => "https://raw.githubusercontent.com/sewiser/WiserSDK_IOS/feature/xcframework/xcframeworks/#{s.name}/#{s.version}/#{s.name}.xcframework.zip" }

  s.ios.deployment_target     = '9.0'

  s.static_framework          = true
  s.vendored_frameworks       = 'WiserSmartActivatorKit.xcframework'

  # s.vendored_frameworks       = 'ios/*.framework'
  # s.vendored_libraries        = 'ios/*.a'

  s.source_files = 'WiserSmartActivatorKit.xcframework/ios-arm64/WiserSmartActivatorKit.framework/Headers/*'


  s.dependency 'WiserSmartActivatorCoreKit'
  s.dependency 'WiserSmartDeviceKit'

  s.pod_target_xcconfig = {
    'TUYA_CODE_SIGN_ENTITLEMENTS' => 'com.apple.developer.networking.wifi-info',
  }

end
