Pod::Spec.new do |s|
  s.name = "WiserSmartActivatorKit"
  s.version = "3.26.5"
  s.summary = "A short description of #{s.name}."
  s.homepage = "https://github.com/sewiser/WiserSDK_IOS"
  s.license = {"type"=>"MIT"}
  s.authors = {"wiser"=>"wiser@wiser.com"}
  s.source = { :git => "https://github.com/sewiser/WiserSDK_IOS.git", :tag => s.version.to_s }

  s.ios.deployment_target     = '9.0'

  s.static_framework          = true
  s.vendored_frameworks       = 'ios/WiserSmartActivatorKit.framework'

  s.source_files = 'ios/WiserSmartActivatorKit.framework/Versions/A/Headers/*.h'

  s.dependency 'WiserSmartActivatorCoreKit'
  s.dependency 'WiserSmartDeviceKit'

end
