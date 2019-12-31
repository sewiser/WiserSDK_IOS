Pod::Spec.new do |s|
  s.name = "WiserSmartMQTTChannelKit"
  s.version = "3.14.0"
  s.summary = "A short description of #{s.name}."
  s.license = {"type"=>"MIT"}
  s.authors = {"wiser"=>"wiser@wiser.com"}
  s.source = { :git => "https://github.com/sewiser/WiserSDK_IOS.git", :tag => s.version.to_s }

  s.ios.deployment_target     = '8.0'

  s.static_framework          = true
  s.vendored_frameworks       = 'ios/*.framework'

  s.dependency 'WiserSmartBaseKit'
  s.dependency 'MQTTClient', '0.15.2'

end
