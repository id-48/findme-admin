import 'package:flutter/material.dart';
import 'package:find_me_admin/screens/Admin/get_all_events.dart';
import 'package:find_me_admin/screens/Admin/get_all_places.dart';
import 'package:find_me_admin/screens/Admin/add_foot_rest_screen.dart';
import 'package:find_me_admin/screens/Admin/add_image_data__screen.dart';
import 'package:find_me_admin/screens/Admin/add_jackbase_screen.dart';
import 'package:find_me_admin/screens/Admin/add_product_screen.dart';
import 'package:find_me_admin/screens/Admin/get_billing_screen.dart';

import '../main.dart';
import '../screens/Admin/AdminLoginScreen.dart';
import '../screens/Admin/add_billing_data__screen.dart';
import '../screens/Admin/get_users_screen.dart';

Route<dynamic>? onGenerateRoute(settings) {
  var uriData = Uri.parse(settings.name!);
  final queryParameters = uriData.queryParameters;

  MaterialPageRoute adminLoginRoute = MaterialPageRoute(
      builder: (context) => AdminLoginScreen(),
      settings: RouteSettings(name: AdminLoginScreen.route));
  MaterialPageRoute getUserRoute = MaterialPageRoute(
      builder: (context) => GetUsersScreen(),
      settings: RouteSettings(name: GetUsersScreen.route));


  if (settings.name == GetUsersScreen.route) {
    return appStore.isAdminLoggedIn != false
        ? MaterialPageRoute(
        builder: (context) => GetUsersScreen(), settings: settings)
        : getUserRoute;
  }

  if (settings.name == GetAllEventsScreen.route) {
    return MaterialPageRoute(
        builder: (context) => GetAllEventsScreen(), settings: settings);
  }

  if (settings.name == GetAllPlacesScreen.route) {
    return MaterialPageRoute(
        builder: (context) => GetAllPlacesScreen(), settings: settings);
  }

  if (settings.name == AddJackBaseScreen.route) {
    return MaterialPageRoute(
        builder: (context) => AddJackBaseScreen(), settings: settings);
  }

  if (settings.name == AddFootRestScreen.route) {
    return MaterialPageRoute(
        builder: (context) => AddFootRestScreen(), settings: settings);
  }

  if (settings.name == ImageDataScreen.route) {
    return MaterialPageRoute(
        builder: (context) => ImageDataScreen(), settings: settings);
  }
  if (settings.name == AddProductScreen.route) {
    return MaterialPageRoute(
        builder: (context) => AddProductScreen(), settings: settings);
  }

  if (settings.name == BillingDataScreen.route) {
    return MaterialPageRoute(
        builder: (context) => BillingDataScreen(), settings: settings);
  }

  if (settings.name == GetBillingScreen.route) {
    return MaterialPageRoute(
        builder: (context) => GetBillingScreen(), settings: settings);
  }

  return null;
}

Map<String, WidgetBuilder> route = {
  AdminLoginScreen.route: (context) => AdminLoginScreen(),
};
