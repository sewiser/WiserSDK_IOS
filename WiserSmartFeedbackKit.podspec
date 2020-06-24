Pod::Spec.new do |s|
  s.name = "WiserSmartFeedbackKit"
  s.version = "3.12.2"
  s.summary = "A short description of #{s.name}."
   s.homepage = "https://github.com/sewiser/WiserSDK_IOS"
   s.license = {"type"=>"MIT"}
   s.authors = {"wiser"=>"wiser@wiser.com"}
  s.source = { :http => "https://airtake-public-data.oss-cn-hangzhou.aliyuncs.com/smart/app/package/sdk/ios/#{s.name}-#{s.version}.zip", :type => "zip" }

  s.static_framework          = true

  s.ios.deployment_target = '8.0'
  s.ios.vendored_frameworks = 'ios/WiserSmartFeedbackKit.framework'
  # s.ios.vendored_libraries = 'ios/*.a'

  s.watchos.deployment_target = '2.0'
  s.watchos.vendored_frameworks = 'watchos/WiserSmartFeedbackKit.framework'
  # s.watchos.vendored_libraries = 'watchos/*.a'

  s.dependency 'WiserSmartBaseKit'

end
