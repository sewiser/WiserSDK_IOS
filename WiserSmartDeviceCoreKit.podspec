Pod::Spec.new do |s|
  s.name = "WiserSmartDeviceCoreKit"
  s.version = "3.19.0"
  s.summary = "A short description of #{s.name}."
  s.license = {"type"=>"MIT"}
  s.authors = {"wiser"=>"wiser@wiser.com"}
  s.homepage = "https://wiser.com"
    s.source = { :git => "https://github.com/sewiser/WiserSDK_IOS.git", :tag => s.version.to_s }

  s.static_framework          = true

  s.ios.deployment_target = '8.0'
  s.ios.vendored_frameworks = 'ios/*.framework'
  # s.ios.vendored_libraries = 'ios/*.a'

  s.watchos.deployment_target = '2.0'
  s.watchos.vendored_frameworks = 'watchos/*.framework'
  # s.watchos.vendored_libraries = 'watchos/*.a'

  s.dependency 'WiserSmartBaseKit'

  s.ios.dependency 'WiserSmartMQTTChannelKit'
  s.ios.dependency 'WiserSmartSocketChannelKit'

end
