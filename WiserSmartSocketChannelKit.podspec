Pod::Spec.new do |s|
  s.name = "WiserSmartSocketChannelKit"
  s.version = "3.19.0"
  s.summary = "A short description of #{s.name}."
  s.homepage = "https://github.com/sewiser/WiserSDK_IOS"
  s.license = {"type"=>"MIT"}
  s.authors = {"wiser"=>"wiser@wiser.com"}
  s.source = { :git => "https://github.com/sewiser/WiserSDK_IOS.git", :tag => s.version.to_s }

  s.ios.deployment_target     = '8.0'

  s.static_framework          = true
  s.vendored_frameworks       = 'ios/WiserSmartSocketChannelKit.framework'

  s.dependency 'WiserSmartBaseKit'
  s.dependency 'CocoaAsyncSocket'

end
