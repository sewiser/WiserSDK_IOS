Pod::Spec.new do |s|
  s.name = "WiserSmartActivatorCoreKit"
  s.version = "3.26.5"
  s.summary = "A short description of #{s.name}."
  s.homepage = "https://github.com/sewiser/WiserSDK_IOS"
  s.license = {"type"=>"MIT"}
  s.authors = {"wiser"=>"wiser@wiser.com"}
  s.source = { :git => "https://github.com/sewiser/WiserSDK_IOS.git", :tag => s.version.to_s }

  s.ios.deployment_target     = '9.0'

  s.static_framework          = true
  s.vendored_frameworks       = 'ios/WiserSmartActivatorCoreKit.framework'

  s.source_files = 'ios/WiserSmartActivatorCoreKit.framework/Versions/A/Headers/*.h'


  s.dependency 'WiserSmartDeviceCoreKit'

end
