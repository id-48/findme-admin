import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:find_me_admin/screens/Admin/AdminLoginScreen.dart';
import 'package:find_me_admin/utils/Extensions/int_extensions.dart';

import '/../main.dart';
import '/../models/models.dart';
import '/../utils/Colors.dart';
import '/../utils/Common.dart';
import '/../utils/Constants.dart';
import '/../utils/DataProvider.dart';
import '/../utils/Extensions/constants.dart';
import '/../utils/Extensions/on_hover.dart';
import '/../utils/Extensions/shared_pref.dart';
import '/../utils/Extensions/string_extensions.dart';
import '/../utils/Extensions/text_styles.dart';
import '/../utils/Extensions/widget_extensions.dart';
import '/../utils/Images.dart';
import '../../utils/ResponsiveWidget.dart';

class BodyCornerWidget extends StatefulWidget {
  final Widget? child;

  BodyCornerWidget({this.child});

  @override
  BodyCornerWidgetState createState() => BodyCornerWidgetState();
}

class BodyCornerWidgetState extends State<BodyCornerWidget> {
  List<MenuItemModel> commonMenuList = getMenuItems();
  List<MenuItemModel> menuList = [];

  @override
  void initState() {
    init();
    super.initState();
  }

  Future<void> init() async {
    menuList.clear();
    // if (getBoolAsync(IS_ADMIN_LOGGED_IN) == true) {
    //   menuList = commonMenuList;
    //   setState(() {});
    // } else {
    userRoleMenu();
    // }
  }

  Future<void> userRoleMenu() async {
    // List<String> getUserRoleName = await getStringListAsync(USER_ROLE) ?? [];
    for (int i = 0; i < commonMenuList.length; i++) {
      // if (getUserRoleName
      //     .where((element) => element == commonMenuList[i].title)
      //     .isNotEmpty) {
      menuList.add(commonMenuList[i]);
      // }
    }
    setState(() {});
  }

  @override
  void setState(fn) {
    if (mounted) super.setState(fn);
  }

  @override
  Widget build(BuildContext context) {
    return Observer(builder: (context) {
      return Scaffold(
        appBar: AppBar(
          elevation: 0,
          toolbarHeight: 60,
          automaticallyImplyLeading: false,
          leadingWidth: MediaQuery
              .of(context)
              .size
              .width,
          leading: Row(
            mainAxisSize: MainAxisSize.min,
            children: [
              InkWell(
                onTap: () {
                  appStore.setExpandedMenu(!appStore.isMenuExpanded);
                },
                child: Row(
                  children: [
                    10.width,
                    Image.asset(app_logo_white,
                        height: 30, width: 30, fit: BoxFit.cover),
                    10.width,
                    if (!ResponsiveWidget.isSmallScreen(context))
                      Text(mAppName,
                          style: boldTextStyle(color: Colors.white, size: 18)),
                  ],
                ),
              ),
            ],
          ),
          actions: [
            PopupMenuButton(
              padding: EdgeInsets.zero,
              child: Padding(
                padding: EdgeInsets.only(right: 16, top: 10, bottom: 10),
                child: Row(
                  children: [
                    Container(
                      height: 60,
                      width: 60,
                      decoration: BoxDecoration(
                        color: Colors.white,
                        border:
                        Border.all(color: Colors.grey.withOpacity(0.15)),
                        shape: BoxShape.circle,
                        // image: DecorationImage(
                        //     image: NetworkImage('${appStore.userProfile}'),
                        //     fit: BoxFit.cover),
                      ),
                    ),
                    if (!ResponsiveWidget.isSmallScreen(context))
                      Column(
                        crossAxisAlignment: CrossAxisAlignment.start,
                        children: [
                          Text('${getStringAsync(NAME)}',
                              style: boldTextStyle(color: Colors.white)),
                          Text(getStringAsync(USER_EMAIL),
                              style: secondaryTextStyle(
                                  size: 14, color: Colors.white)),
                        ],
                      ),
                  ],
                ),
              ),
              itemBuilder: (_) =>
              [
                PopupMenuItem(
                  value: 1,
                  child: Row(
                    children: [
                      Icon(Icons.logout, color: Colors.grey),
                      SizedBox(width: 8),
                      Text("Logout"),
                    ],
                  ),
                  textStyle: primaryTextStyle(),
                ),
              ],
              onSelected: (value) async {
                if (value == 1) {
                  clearSharedPref();
                  await Navigator.pushReplacementNamed(
                      context, AdminLoginScreen.route);
                }
              },
            ),
          ],
        ),
        body: Container(
          height: MediaQuery
              .of(context)
              .size
              .height,
          width: MediaQuery
              .of(context)
              .size
              .width,
          child: Stack(
            children: [
              AnimatedContainer(
                duration: Duration(milliseconds: 200),
                width: getMenuWidth(),
                child: Container(
                  color: primaryColor,
                  padding: EdgeInsets.only(top: 16),
                  width: getMenuWidth(),
                  child: Column(
                    children: [
                      10.height,
                      ListView(
                        children: menuList.map((item) {
                          return HoverWidget(builder: (context, isHovering) {
                            return InkWell(
                              child: Container(
                                margin: EdgeInsets.only(bottom: 16),
                                alignment: Alignment.centerLeft,
                                padding: EdgeInsets.only(
                                    left: 16, top: 8, bottom: 8, right: 0),
                                decoration: BoxDecoration(
                                  color:
                                  appStore.selectedMenuIndex == item.index
                                      ? hoverColor
                                      : isHovering
                                      ? hoverColor
                                      : Colors.transparent,
                                ),
                                child: Row(
                                  children: [
                                    Tooltip(
                                        child: ImageIcon(
                                            AssetImage(item.imagePath!),
                                            size: 24,
                                            color: Colors.white),
                                        message: item.title.validate()),
                                    appStore.isMenuExpanded
                                        ? Expanded(
                                      child: Padding(
                                        padding:
                                        EdgeInsets.only(left: 16),
                                        child: Text(
                                          item.title!,
                                          maxLines: 1,
                                          style:
                                          appStore.selectedMenuIndex ==
                                              item.index
                                              ? boldTextStyle(
                                              color: Colors.white,
                                              size: 14)
                                              : primaryTextStyle(
                                              color: Colors.white,
                                              size: 14),
                                        ),
                                      ),
                                    )
                                        : Spacer(),
                                    appStore.selectedMenuIndex == item.index
                                        ? Card(
                                      margin: EdgeInsets.zero,
                                      color: Theme
                                          .of(context)
                                          .cardColor,
                                      shape: BeveledRectangleBorder(
                                          borderRadius:
                                          BorderRadius.circular(30)),
                                      child:
                                      SizedBox(width: 30, height: 30),
                                    )
                                        : SizedBox(),
                                  ],
                                ),
                              ),
                              onTap: () {
                                if (appStore.selectedMenuIndex != item.index!) {
                                  appStore.setSelectedMenuIndex(item.index!);
                                  Navigator.pushNamed(context, item.route!);
                                }
                              },
                            );
                          });
                        }).toList(),
                      ).expand(),
                    ],
                  ),
                ),
              ),
              Positioned(
                left: getMenuWidth() - 15,
                right: 0,
                child: AnimatedContainer(
                  duration: Duration(milliseconds: 200),
                  alignment: AlignmentDirectional.topStart,
                  width: getBodyWidth(context),
                  height: MediaQuery
                      .of(context)
                      .size
                      .height,
                  decoration: BoxDecoration(
                    color: Theme
                        .of(context)
                        .cardColor,
                    borderRadius: BorderRadius.only(
                      topLeft: Radius.circular(defaultRadius),
                    ),
                  ),
                  child: widget.child,
                ),
              ),
            ],
          ),
        ),
      );
    });
  }
}
