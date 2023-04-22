# WunderLINQ Insta360 Remote iOS App

The WunderLINQ Insta360 app is for use with the [WunderLINQ Hardware](https://www.wunderlinq.com)

The WunderLINQ is a combination of Plug-and-Play hardware that snaps into your existing BMW Motorcycle 
Navigation Prep and a companion app for your Android or iOS phone or tablet.  Together they allow you 
to control your mobile device and other connected devices like Insta360 cameras from your handlebar wheel.  
If your motorcycle also has the On Board Computer Pro option the WunderLINQ can also receive and 
decode performance and fault data.

<a href="https://apps.apple.com/us/app/wunderlinq-insta360-remote/id1671376660" target="_blank">
<img src="https://blackboxembedded.github.io/WunderLINQ-Documentation/en/images-localized/badge_store_appstore.png" alt="Get it on AppStore" height="60"/></a>

<p>
<a href="https://weblate.blackboxembedded.com/engage/wunderlinq/">
<img src="https://weblate.blackboxembedded.com/widgets/wunderlinq/-/wunderlinq-insta360-ios/svg-badge.svg" alt="Translation status" />
</a>
</p>

## Build Instructions
1. Clone the project and open the workspace in Xcode

2. Obtain SDK access from [Insta360](https://www.insta360.com/sdk/home)

3. Create Cartfile per the [Insta360 SDK](https://github.com/Insta360Develop/CameraSDK-iOS) documentation

4. Pull down dependencies
```
carthage update
pod install
```
5. Build and Run
