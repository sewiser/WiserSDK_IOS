Pod::Spec.new do |s|
  s.name = "WiserSmartDeviceKit"
  s.version = "3.14.1"
  s.summary = "A short description of #{s.name}."
  s.homepage = "https://github.com/sewiser/WiserSDK_IOS"
  s.license = {"type"=>"MIT"}
  s.authors = {"wiser"=>"wiser@wiser.com"}
  s.source = { :git => "https://github.com/sewiser/WiserSDK_IOS.git", :tag => s.version.to_s }

  s.static_framework          = true

  s.ios.deployment_target = '8.0'
  s.ios.vendored_frameworks = 'ios/WiserSmartDeviceKit.framework'

  s.watchos.deployment_target = '2.0'
  s.watchos.vendored_frameworks = 'watchos/WiserSmartDeviceKit.framework'

  s.dependency 'WiserSmartBaseKit'

  s.ios.dependency 'WiserSmartMQTTChannelKit'
  s.ios.dependency 'WiserSmartSocketChannelKit'

end
