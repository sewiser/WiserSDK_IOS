Pod::Spec.new do |s|
  s.name = "WiserSmartDeviceCoreKit"
  s.version = "3.26.6"
  s.summary = "A short description of #{s.name}."
  s.license = {"type"=>"MIT"}
  s.authors = {"0x5e"=>"gaosen.wiser.com"}
  s.homepage = "https:/.wiser.com"
  s.source = { :http => "https://raw.githubusercontent.com/sewiser/WiserSDK_IOS/master/xcframeworks/#{s.name}/#{s.version}/#{s.name}.xcframework.zip" }

  s.static_framework          = true

  s.ios.deployment_target = '9.0'
  # s.ios.vendored_frameworks = 'ios/*.framework'

  # s.ios.vendored_libraries = 'ios/*.a'

  s.watchos.deployment_target = '2.0'
  # s.watchos.vendored_frameworks = 'watchos/*.framework'
  # s.watchos.vendored_libraries = 'watchos/*.a'

  s.source_files = 'WiserSmartDeviceCoreKit.xcframework/ios-arm64/WiserSmartDeviceCoreKit.framework/Headers/*'

  s.vendored_frameworks = 'WiserSmartDeviceCoreKit.xcframework'


  s.dependency 'WiserSmartBaseKit'

  s.ios.dependency 'WiserSmartMQTTChannelKit'
  s.ios.dependency 'WiserSmartSocketChannelKit'

  s.pod_target_xcconfig = {
    'TUYA_CODE_SIGN_ENTITLEMENTS' => 'com.apple.developer.networking.wifi-info',
  }

end
