Pod::Spec.new do |s|
  s.name = "WiserSmartActivatorCoreKit"
  s.version = "3.26.6"
  s.summary = "A short description of #{s.name}."
  s.license = {"type"=>"MIT"}
  s.authors = {"0x5e"=>"gaosen.wiser.com"}
  s.homepage = "https:/.wiser.com"
  s.source = { :http => "https://raw.githubusercontent.com/sewiser/WiserSDK_IOS/feature/xcframework/xcframeworks/#{s.name}/#{s.version}/#{s.name}.xcframework.zip" }
  s.ios.deployment_target     = '9.0'

  s.static_framework          = true
  s.vendored_frameworks       = 'WiserSmartActivatorCoreKit.xcframework'
  # s.vendored_libraries        = 'ios/*.a'

  s.source_files = 'WiserSmartActivatorCoreKit.xcframework/ios-arm64/WiserSmartActivatorCoreKit.framework/Headers/*'


  s.dependency 'WiserSmartDeviceCoreKit'

  s.pod_target_xcconfig = {
    'TUYA_CODE_SIGN_ENTITLEMENTS' => 'com.apple.developer.networking.wifi-info',
  }

end
