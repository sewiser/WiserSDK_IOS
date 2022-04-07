Pod::Spec.new do |s|
  s.name = "WiserSmartBaseKit"
  s.version = "3.26.6"
  s.summary = "A short description of #{s.name}."
  s.homepage = "https://github.com/sewiser/WiserSDK_IOS"
  s.license = {"type"=>"MIT"}
  s.authors = {"wiser"=>"wiser@wiser.com"}
  s.source = { :git => "https://github.com/sewiser/WiserSDK_IOS.git", :tag => s.version.to_s }

  s.static_framework = true

  s.ios.deployment_target = '9.0'
  s.ios.vendored_frameworks = 'ios/WiserSmartBaseKit.framework'
  s.ios.resources = 'ios/WiserSmartBaseKit.framework/Versions/A/Resources/*'
  s.source_files = 'ios/WiserSmartBaseKit.framework/Versions/A/Headers/*.h'

  s.watchos.deployment_target = '2.0'
  s.watchos.vendored_frameworks = 'watchos/WiserSmartBaseKit.framework'
  s.watchos.resources = 'watchos/WiserSmartBaseKit.framework/Versions/A/Resources/*'

  s.libraries = 'c++', 'z'

  s.dependency 'WiserSmartUtil'
  s.dependency 'YYModel'

end
