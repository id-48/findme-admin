import 'package:firebase_remote_config/firebase_remote_config.dart';

class GetAuthCredential {
  static final GetAuthCredential _singleton = GetAuthCredential._internal();

  factory GetAuthCredential() {
    return _singleton;
  }

  GetAuthCredential._internal();

  final remoteConfig = FirebaseRemoteConfig.instance;
  String email = '';
  String password = '';

  initializeConfig() async {
    await remoteConfig.setConfigSettings(RemoteConfigSettings(
      fetchTimeout: const Duration(seconds: 1),
      minimumFetchInterval: const Duration(seconds: 1),
    ));
    await remoteConfig.fetchAndActivate();
    getConfigValue();
  }

  getConfigValue() {
    email = remoteConfig.getString('email');
    password = remoteConfig.getString('password');
    print('email == ${email}');
    print('password == ${password}');
  }
}
