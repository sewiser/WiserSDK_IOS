Pod::Spec.new do |s|
  s.name = "WiserSmartActivatorKit"
  s.version = "3.14.0"
  s.summary = "A short description of #{s.name}."
  s.homepage = "https://github.com/sewiser/WiserSDK_IOS"
  s.license = {"type"=>"MIT"}
  s.authors = {"wiser"=>"wiser@wiser.com"}
  s.source = { :git => "https://github.com/sewiser/WiserSDK_IOS.git", :tag => s.version.to_s }

  s.ios.deployment_target     = '8.0'

  s.static_framework          = true
  s.vendored_frameworks       = 'ios/WiserSmartActivatorKit.framework'

  s.dependency 'WiserSmartDeviceKit'
  s.dependency 'Reachability'

end
