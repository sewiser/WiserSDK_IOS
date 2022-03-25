Pod::Spec.new do |s|
  s.name = "WiserSmartTimerKit"
  s.version = "3.26.5"
  s.summary = "A short description of #{s.name}."
  s.homepage = "https://github.com/sewiser/WiserSDK_IOS"
  s.license = {"type"=>"MIT"}
  s.authors = {"wiser"=>"wiser@wiser.com"}
  s.source = { :git => "https://github.com/sewiser/WiserSDK_IOS.git", :tag => s.version.to_s }

  s.static_framework          = true

  s.ios.deployment_target = '9.0'
  s.ios.vendored_frameworks = 'ios/WiserSmartTimerKit.framework'

  s.watchos.deployment_target = '2.0'
  s.watchos.vendored_frameworks = 'watchos/WiserSmartTimerKit.framework'
  
  s.source_files = 'ios/WiserSmartTimerKit.framework/Versions/A/Headers/*.h'

  s.dependency 'WiserSmartBaseKit'
  s.dependency 'WiserSmartDeviceKit'

end
