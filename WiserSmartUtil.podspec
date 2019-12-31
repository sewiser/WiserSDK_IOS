Pod::Spec.new do |s|
  s.name = "WiserSmartUtil"
  s.version = "3.14.0"
  s.summary = "A short description of #{s.name}."
  s.license = {"type"=>"MIT"}
  s.authors = {"wiser"=>"wiser@wiser.com"}
  s.source = { :git => "https://github.com/sewiser/WiserSDK_IOS.git", :tag => s.version.to_s }

  s.static_framework = true

  s.ios.deployment_target = '8.0'
  s.ios.vendored_frameworks = 'ios/*.framework'
  s.ios.frameworks = 'CoreTelephony', 'Foundation', 'SystemConfiguration', 'UIKit'
  s.ios.resources = 'ios/*.framework/Versions/A/Resources/*'

  s.watchos.deployment_target = '2.0'
  s.watchos.vendored_frameworks = 'watchos/*.framework'
  s.watchos.frameworks = 'WatchKit'
  s.watchos.resources = 'watchos/*.framework/Versions/A/Resources/*'

end
