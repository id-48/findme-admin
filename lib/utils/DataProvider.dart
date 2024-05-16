import 'package:find_me_admin/models/admin_model/get_all_admin.dart';
import 'package:find_me_admin/screens/Admin/add_foot_rest_screen.dart';
import 'package:find_me_admin/screens/Admin/add_image_data__screen.dart';
import 'package:find_me_admin/screens/Admin/add_jackbase_screen.dart';
import 'package:find_me_admin/screens/Admin/add_product_screen.dart';
import 'package:find_me_admin/screens/Admin/get_all_events.dart';
import 'package:find_me_admin/screens/Admin/get_all_places.dart';
import 'package:find_me_admin/screens/Admin/get_billing_screen.dart';
import 'package:find_me_admin/screens/Admin/get_users_screen.dart';
import 'package:find_me_admin/screens/Admin/register_admin_screen.dart';
import 'package:find_me_admin/utils/Extensions/shared_pref.dart';
import 'package:flutter/material.dart';

import '../models/models.dart';
import '../utils/Constants.dart';

List<MenuItemModel> getMenuItems() {
  List<MenuItemModel> list = [];

  if (getBoolAsync(IS_ADMIN_LOGGED_IN) == true) {
    list.add(MenuItemModel(
        index: get_admin_index,
        imagePath: 'assets/icons/ic_dashboard.png',
        title: "All Admin",
        route: RegisterAdminScreen.route));
    list.add(MenuItemModel(
        index: get_users_index,
        imagePath: 'assets/icons/ic_dashboard.png',
        title: "All Users",
        route: GetUsersScreen.route));
    list.add(MenuItemModel(
        index: get_all_event,
        imagePath: 'assets/icons/ic_extra_charges.png',
        title: "All Events",
        route: GetAllEventsScreen.route));

    list.add(MenuItemModel(
        index: get_all_places,
        imagePath: 'assets/icons/ic_extra_charges.png',
        title: "All Places",
        route: GetAllPlacesScreen.route));
    //
    //   list.add(MenuItemModel(
    //       index: add_jackbase_index,
    //       imagePath: 'assets/icons/ic_extra_charges.png',
    //       title: "JACK & BASE",
    //       route: AddJackBaseScreen.route));
    //
    //   list.add(MenuItemModel(
    //       index: add_footrest_index,
    //       imagePath: 'assets/icons/ic_extra_charges.png',
    //       title: "FOOT REST",
    //       route: AddFootRestScreen.route));
    //
    //   list.add(MenuItemModel(
    //       index: add_imageData_index,
    //       imagePath: 'assets/icons/ic_extra_charges.png',
    //       title: "IMAGE DATA",
    //       route: ImageDataScreen.route));
    //
    //   list.add(MenuItemModel(
    //       index: add_product_index,
    //       imagePath: 'assets/icons/ic_extra_charges.png',
    //       title: "PRODUCT",
    //       route: AddProductScreen.route));
    //
    //   // list.add(MenuItemModel(
    //   //     index: add_billingData_index,
    //   //     imagePath: 'assets/icons/ic_extra_charges.png',
    //   //     title: "BILLING DATA",
    //   //     route: BillingDataScreen.route));
    // }
    //
    // list.add(MenuItemModel(
    //     index: get_billing_index,
    //     imagePath: 'assets/icons/ic_extra_charges.png',
    //     title: "BILLING DATA",
    //     route: GetBillingScreen.route));
  }

  return list;
}

class ClientMenuItemModel {
  int? index;
  String? title;
  Widget? widget;
  String? widgetRoute;
  bool? mISCheck;
  IconData? img;
  String? link;

  ClientMenuItemModel(
      {this.index, this.title, this.widget, this.mISCheck = false, this.img, this.widgetRoute, this.link});
}

class StaticDashboardModel {
  String? name;
  String? description;
  String? img;
  int? ind;
  String? widgetRoute;
  Widget? onTap;

  StaticDashboardModel({this.name, this.description, this.img, this.ind, this.onTap, this.widgetRoute});
}

class FilterAttributeModel {
  String? orderStatus;
  String? fromDate;
  String? toDate;

  FilterAttributeModel({this.orderStatus, this.fromDate, this.toDate});

  FilterAttributeModel.fromJson(Map<String, dynamic> json) {
    orderStatus = json['order_status'];
    fromDate = json['from_date'];
    toDate = json['to_date'];
  }

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = new Map<String, dynamic>();
    data['order_status'] = this.orderStatus;
    data['from_date'] = this.fromDate;
    data['to_date'] = this.toDate;
    return data;
  }
}

class FooterPageSocialLinkModel {
  int? ind;
  String? name;
  String? link;
  Icon? icon;
  IconData? img;

  FooterPageSocialLinkModel({this.ind, this.name, this.link, this.icon});
}
