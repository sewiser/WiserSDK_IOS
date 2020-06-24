Pod::Spec.new do |s|
  s.name = "WiserSmartSceneKit"
  s.version = "3.14.3"
  s.summary = "A short description of #{s.name}."
  s.homepage = "https://github.com/sewiser/WiserSDK_IOS"
   s.license = {"type"=>"MIT"}
   s.authors = {"wiser"=>"wiser@wiser.com"}
   s.source = { :git => "https://github.com/sewiser/WiserSDK_IOS.git", :tag => s.version.to_s }
  s.static_framework          = true

  s.ios.deployment_target = '8.0'
  s.ios.vendored_frameworks = 'ios/WiserSmartSceneKit.framework'
  # s.ios.vendored_libraries = 'ios/*.a'

  s.watchos.deployment_target = '2.0'
  s.watchos.vendored_frameworks = 'watchos/WiserSmartSceneKit.framework'
  # s.watchos.vendored_libraries = 'watchos/*.a'

  s.dependency 'WiserSmartBaseKit'
  s.dependency 'WiserSmartDeviceKit'

end
