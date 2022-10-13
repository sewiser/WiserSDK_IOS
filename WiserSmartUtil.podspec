Pod::Spec.new do |s|
  s.name = "WiserSmartUtil"
  s.version = "3.26.6"
  s.summary = "A short description of #{s.name}."
  s.license = {"type"=>"MIT"}
  s.authors = {"0x5e"=>"gaosen.wiser.com"}
  s.homepage = "https:/.wiser.com"
  s.source = { :http => "https://raw.githubusercontent.com/sewiser/WiserSDK_IOS/master/xcframeworks/#{s.name}/#{s.version}/#{s.name}.xcframework.zip" }
                      
  s.ios.deployment_target = '9.0'
  s.ios.frameworks = 'CoreTelephony', 'Foundation', 'SystemConfiguration', 'UIKit'
  # s.ios.vendored_libraries = 'Carthage/Build/iOS/*.a'
  s.ios.pod_target_xcconfig  = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.ios.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

  s.watchos.deployment_target = '2.0'
  s.watchos.frameworks = 'WatchKit'
  # s.watchos.vendored_libraries = 'Carthage/Build/watchOS/*.a'
  s.vendored_frameworks = 'WiserSmartUtil.xcframework'
  s.resources = 'WiserSmartUtil.xcframework/**/*.bundle'
  

  s.source_files = 'WiserSmartUtil.xcframework/ios-arm64/WiserSmartUtil.framework/Headers/*.h'
  
  s.dependency 'OpenSSL-Universal', '1.0.2.17'

end
