// swift-tools-version:5.4
import PackageDescription

let package = Package(
    name: "FlipFlopSDK",
    platforms: [
        .iOS(.v11)
    ],
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "FlipFlopSDK",
            targets: ["FlipFlopSDK", "FlipFlopSDK-WebRTC", "FlipFlopSDK-AWSCore", "FlipFlopSDK-AWSLogs", "FlipFlopSDK-AWSS3", "FlipFlopSDK-SocketRocket"])
    ],
    dependencies: [
        // Dependencies declare other packages that this package depends on.
    ],
    targets: [
        .binaryTarget(
            name: "FlipFlopSDK",
            path: "FlipFlopSDK.xcframework"
        ),
        .binaryTarget(
            name: "FlipFlopSDK-WebRTC",
            path: "WebRTC.xcframework"
        ),
        .binaryTarget(
            name: "FlipFlopSDK-AWSCore",
            path: "AWSCore.xcframework"
        ),
        .binaryTarget(
            name: "FlipFlopSDK-AWSLogs",
            path: "AWSLogs.xcframework"
        ),
        .binaryTarget(
            name: "FlipFlopSDK-AWSS3",
            path: "AWSS3.xcframework"
        ),
        .binaryTarget(
            name: "FlipFlopSDK-SocketRocket",
            path: "SocketRocket.xcframework"
        )
    ]
)
