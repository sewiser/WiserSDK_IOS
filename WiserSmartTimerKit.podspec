Pod::Spec.new do |s|
  s.name = "WiserSmartTimerKit"
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
  
  # s.source_files = 'ios/*.framework/Versions/A/Headers/*.h'

  s.source_files = 'WiserSmartTimerKit.xcframework/ios-arm64/WiserSmartTimerKit.framework/Headers/*'

  s.vendored_frameworks = 'WiserSmartTimerKit.xcframework'

  s.dependency 'WiserSmartBaseKit'
  s.dependency 'WiserSmartDeviceKit'

end
