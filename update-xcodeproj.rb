#!/usr/bin/env ruby
require 'xcodeproj'

def update_deployment_config(config = nil)
    return if config.nil?
    config.build_settings['SDKROOT'] = 'macosx'
    config.build_settings['ORDER_FILE'] = '$(SRCROOT)/libobjc.order'
    config.build_settings['ONLY_ACTIVE_ARCH'] = 'YES'
end

def update_xcodeproj(path)
    begin
        project = Xcodeproj::Project.open(path)
        project.targets.each do |target|
            target.build_configurations.each do |config|
                update_deployment_config(config)
            end
        end
        project.build_configurations.each do |config|
            update_deployment_config(config)
        end
        project.save()
    rescue Error => msg
        puts "#{msg}"
    end
end
update_xcodeproj('objc.xcodeproj')

