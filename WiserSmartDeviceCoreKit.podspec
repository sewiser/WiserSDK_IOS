Pod::Spec.new do |s|
  s.name = "WiserSmartDeviceCoreKit"
  s.version = "3.26.5"
  s.summary = "A short description of #{s.name}."
  s.homepage = "https://github.com/sewiser/WiserSDK_IOS"
  s.license = {"type"=>"MIT"}
  s.authors = {"wiser"=>"wiser@wiser.com"}
  s.source = { :git => "https://github.com/sewiser/WiserSDK_IOS.git", :tag => s.version.to_s }

  s.static_framework          = true

  s.ios.deployment_target = '9.0'
  s.ios.vendored_frameworks = 'ios/WiserSmartDeviceCoreKit.framework'

  s.watchos.deployment_target = '2.0'
  s.watchos.vendored_frameworks = 'watchos/WiserSmartDeviceCoreKit.framework'

  s.source_files = 'ios/WiserSmartDeviceCoreKit.framework/Versions/A/Headers/*.h'

  s.dependency 'WiserSmartBaseKit'

  s.ios.dependency 'WiserSmartMQTTChannelKit'
  s.ios.dependency 'WiserSmartSocketChannelKit'

end
