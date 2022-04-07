Pod::Spec.new do |s|
  s.name = "WiserSmartUtil"
  s.version = "3.26.6"
  s.summary = "A short description of #{s.name}."
  s.homepage = "https://github.com/sewiser/WiserSDK_IOS"
  s.license = {"type"=>"MIT"}
  s.authors = {"wiser"=>"wiser@wiser.com"}
  s.source = { :git => "https://github.com/sewiser/WiserSDK_IOS.git", :tag => s.version.to_s }

  s.ios.deployment_target = '9.0'
  s.ios.frameworks = 'CoreTelephony', 'Foundation', 'SystemConfiguration', 'UIKit'
  s.ios.resources = 'ios/WiserSmartUtil.framework/**/*.bundle'
  s.ios.vendored_frameworks = 'ios/WiserSmartUtil.framework'
  s.ios.pod_target_xcconfig  = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.ios.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

  s.watchos.deployment_target = '2.0'
  s.watchos.frameworks = 'WatchKit'
  s.watchos.resources = 'watchos/WiserSmartUtil.framework/**/*.bundle'
  s.watchos.vendored_frameworks = 'watchos/WiserSmartUtil.framework'

  s.source_files = 'ios/WiserSmartUtil.framework/Versions/A/Headers/*.h'

  s.dependency 'OpenSSL-Universal', '1.0.2.17'
  
  
end
