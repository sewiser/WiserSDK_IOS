Pod::Spec.new do |s|
  s.name = "WiserSmartBaseKit"
  s.version = "3.26.6"
  s.summary = "A short description of #{s.name}."
  s.license = {"type"=>"MIT"}
  s.authors = {"0x5e"=>"gaosen.wiser.com"}
  s.homepage = "https:/.wiser.com"
  s.source = { :http => "https://raw.githubusercontent.com/sewiser/WiserSDK_IOS/master/xcframeworks/#{s.name}/#{s.version}/#{s.name}.xcframework.zip" }

  s.static_framework = true

  s.ios.deployment_target = '9.0'
  # s.ios.vendored_frameworks = 'ios/*.framework'
  # s.ios.vendored_libraries = 'ios/*.a'
  # s.ios.resources = 'ios/*.framework/Versions/A/Resources/*'
  # s.ios.source_files = 'Carthage/WiserSmartBaseKit.xcframework/ios-arm64/WiserSmartBaseKit.framework/Headers/*'

  s.watchos.deployment_target = '2.0'
  # s.watchos.vendored_frameworks = 'watchos/*.framework'
  # s.watchos.vendored_libraries = 'watchos/*.a'
  # s.watchos.source_files = 'Carthage/WiserSmartBaseKit.xcframework/watchos-arm64_arm64_32_armv7k/WiserSmartBaseKit.framework/Headers/*'

  s.libraries = 'c++', 'z'

  s.source_files = 'WiserSmartBaseKit.xcframework/**/*/Headers/*'

  s.ios.vendored_frameworks = 'WiserSmartBaseKit.xcframework'

  s.dependency 'WiserSmartUtil'
  s.dependency 'YYModel'

  s.pod_target_xcconfig = {
    'TUYA_CODE_SIGN_ENTITLEMENTS' => 'com.apple.security.application-groups',
  }

end
