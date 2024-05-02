import 'package:find_me_admin/utils/Extensions/remote_config.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:flutter/gestures.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_web_plugins/url_strategy.dart';
import 'package:find_me_admin/screens/Admin/AdminLoginScreen.dart';
import 'package:find_me_admin/screens/Admin/get_users_screen.dart';
import 'package:find_me_admin/utils/Extensions/shared_pref.dart';
import 'package:find_me_admin/utils/RouteGenerator.dart';
import 'package:shared_preferences/shared_preferences.dart';
import '../appTheme.dart';
import '../store/AppStore.dart';
import '../utils/Constants.dart';
import '../utils/Extensions/common.dart';
import '../utils/Extensions/int_extensions.dart';

AppStore appStore = AppStore();

final navigatorKey = GlobalKey<NavigatorState>();

get getContext => navigatorKey.currentState?.overlay?.context;

late SharedPreferences sharedPref;

PageRouteAnimation? pageRouteAnimationGlobal;
Duration pageRouteTransitionDurationGlobal = 400.milliseconds;

Future<String> loadBuilderData() async {
  return await rootBundle.loadString('assets/builder.json');
}


void main() async {
  setUrlStrategy(PathUrlStrategy());
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp(options: firebaseOptions);
  GetAuthCredential().initializeConfig();

  // Hive.init(path);
  sharedPref = await SharedPreferences.getInstance();
  setStringAsync('TOKEN', authToken);
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Observer(builder: (context) {
      return MaterialApp(
        builder: (context, child) {
          return ScrollConfiguration(
            behavior: ScrollConfiguration.of(context).copyWith(
              dragDevices: {
                PointerDeviceKind.mouse,
                PointerDeviceKind.touch,
              },
            ),
            child: child!,
          );
        },
        initialRoute: getBoolAsync(IS_LOGGED_IN) == false
            ? AdminLoginScreen.route
            : getBoolAsync(IS_ADMIN_LOGGED_IN) == true
                ? GetUsersScreen.route
                : getStringAsync(USER_FIRST_ROLE),

        routes: route,
        // home: GetMobileBillingScreen(),
        onGenerateRoute: onGenerateRoute,
        navigatorKey: navigatorKey,
        debugShowCheckedModeBanner: false,
        title: mAppName,
        theme: AppTheme.lightTheme,
        darkTheme: AppTheme.darkTheme,
        themeMode: ThemeMode.light,
        localeResolutionCallback: (locale, supportedLocales) => locale,
        scrollBehavior: SBehavior(),
      );
    });
  }
}
