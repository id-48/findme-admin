import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:find_me_admin/components/AddButtonComponent.dart';
import 'package:find_me_admin/components/Admin/BodyCornerWidget.dart';
import 'package:find_me_admin/components/Admin/add_user_dialog.dart';
import 'package:find_me_admin/components/CommonConfirmationDialog.dart';
import 'package:find_me_admin/components/PaginationWidget.dart';
import 'package:find_me_admin/main.dart';
import 'package:find_me_admin/models/showroom/get_showroom/res_get_showroom.dart';
import 'package:find_me_admin/network/RestApis.dart';
import 'package:find_me_admin/utils/Colors.dart';
import 'package:find_me_admin/utils/Common.dart';
import 'package:find_me_admin/utils/Constants.dart';
import 'package:find_me_admin/utils/Extensions/constants.dart';
import 'package:find_me_admin/utils/Extensions/shared_pref.dart';
import 'package:find_me_admin/utils/Extensions/text_styles.dart';
import 'package:find_me_admin/utils/ResponsiveWidget.dart';
import 'package:find_me_admin/utils/toast.dart';

import '../../models/user_model/get_user_profile.dart';
import '../../models/user_model/res_get_all_user.dart';

class GetUsersScreen extends StatefulWidget {
  static String route = '/admin/getUsers';

  @override
  State<GetUsersScreen> createState() => _GetUsersScreenState();
}

class _GetUsersScreenState extends State<GetUsersScreen> {
  ScrollController horizontalScrollController = ScrollController();

  int currentPage = 1;
  int totalPage = 1;
  var perPage = 10;

  List<User> lstAllUsers = [];

  @override
  void initState() {
    init();
    super.initState();
  }

  Future<void> init() async {
    appStore.setSelectedMenuIndex(get_users_index);
    getUserApiCall();
  }

  getUserApiCall() async {
    await getAllUsers(limit: perPage, page: currentPage).then((value) {
      if (value.status == true) {
        lstAllUsers = value.user;
        setState(() {});
      }
    });
  }

  @override
  void setState(fn) {
    if (mounted) super.setState(fn);
  }

  @override
  Widget build(BuildContext context) {
    Widget addUserButton() {
      return AddButtonComponent("Add User", () {
        showDialog(
          context: context,
          barrierDismissible: false,
          builder: (BuildContext dialogContext) {
            return AddUserDialog();
          },
        );
      });
    }

    return Observer(builder: (context) {
      return BodyCornerWidget(
        child: Stack(
          fit: StackFit.expand,
          children: [
            SingleChildScrollView(
              padding: EdgeInsets.all(16),
              scrollDirection: Axis.vertical,
              controller: ScrollController(),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  ResponsiveWidget.isSmallScreen(context) &&
                      appStore.isMenuExpanded
                      ? Wrap(
                    spacing: 16,
                    runSpacing: 16,
                    crossAxisAlignment: WrapCrossAlignment.center,
                    children: [
                      Text("Add User", style: boldTextStyle(size: 20,
                          color: primaryColor)),
                      addUserButton(),
                    ],
                  )
                      : Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      Text("Add User", style: boldTextStyle(size: 20,
                          color: primaryColor)),
                      addUserButton(),
                    ],
                  ),
                  Column(
                    mainAxisAlignment: MainAxisAlignment.start,
                    children: [
                      SizedBox(height: 16),
                      RawScrollbar(
                        scrollbarOrientation: ScrollbarOrientation.bottom,
                        controller: horizontalScrollController,
                        thumbVisibility: true,
                        thumbColor: Colors.black12,
                        radius: Radius.circular(defaultRadius),
                        child: Container(
                          decoration: BoxDecoration(
                              color: Colors.white,
                              borderRadius: BorderRadius.circular(
                                  defaultRadius),
                              boxShadow: commonBoxShadow()),
                          child: SingleChildScrollView(
                            padding: EdgeInsets.all(16),
                            scrollDirection: Axis.horizontal,
                            controller: horizontalScrollController,
                            child: ConstrainedBox(
                              constraints: BoxConstraints(
                                  minWidth: getBodyWidth(context) - 48),
                              child: DataTable(
                                dataRowHeight: 45,
                                headingRowHeight: 45,
                                horizontalMargin: 16,
                                headingRowColor:
                                MaterialStateColor.resolveWith((states) =>
                                    primaryColor.withOpacity(0.1)),
                                showCheckboxColumn: false,
                                dataTextStyle: primaryTextStyle(size: 14),
                                headingTextStyle: boldTextStyle(),
                                columns: [
                                  DataColumn(label: Text("No")),
                                  DataColumn(label: Text("Name")),
                                  DataColumn(label: Text("Mobile No")),
                                  DataColumn(label: Text("Latitude")),
                                  DataColumn(label: Text("Longitude")),
                                  DataColumn(label: Text("Address")),
                                  DataColumn(label: Text("Country")),
                                  DataColumn(label: Text("Edit")),
                                ],
                                rows: lstAllUsers.map((mData) {
                                  return DataRow(cells: [
                                    DataCell(Text(
                                        "${lstAllUsers.indexOf(mData) + 1}")),
                                    DataCell(Text(mData.userName)),
                                    DataCell(Text(mData.mono)),
                                    DataCell(Text(mData.lattitude)),
                                    DataCell(Text(mData.longtitude)),
                                    DataCell(Text(mData.address)),
                                    DataCell(Text(mData.countryName)),
                                    DataCell(
                                      Row(
                                        children: [
                                          Row(
                                            children: [
                                              outlineActionIcon(
                                                  Icons.edit, Colors.green,
                                                  "Edit", () {
                                                showDialog(
                                                    context: context,
                                                    barrierDismissible: false,
                                                    builder: (
                                                        BuildContext dialogContext) {
                                                      print('mData ::${mData
                                                          .toJson()}');
                                                      return AddUserDialog(
                                                        userData: mData,
                                                        onUpdate: () {},
                                                      );
                                                    });
                                              }),
                                              SizedBox(width: 8),
                                            ],
                                          ),
                                          outlineActionIcon(
                                              Icons.delete, Colors.red,
                                              "Delete", () {
                                            commonConfirmationDialog(context,
                                                DIALOG_TYPE_DELETE, () {
                                                  if (getStringAsync(
                                                      USER_TYPE) ==
                                                      DEMO_ADMIN) {
                                                    ToastUtils.showCustomToast(
                                                        context,
                                                        "Are you sure you want to delete data",
                                                        "warning");
                                                  } else {
                                                    deleteUserApi(
                                                        userId: mData.id).then((
                                                        value) {
                                                      if (value.status ==
                                                          true) {
                                                        ToastUtils
                                                            .showCustomToast(
                                                            context,
                                                            value.message,
                                                            "success");

                                                        Navigator.pushNamed(
                                                            context,
                                                            GetUsersScreen
                                                                .route);
                                                      } else {
                                                        ToastUtils
                                                            .showCustomToast(
                                                            context,
                                                            value.message,
                                                            "warning");
                                                      }
                                                    });
                                                  }
                                                },
                                                isForceDelete: mData
                                                    .updatedAt != "",
                                                title: "Delete data",
                                                subtitle: "Are you sure you want to delete Showroom?");
                                          }),
                                        ],
                                      ),
                                    ),
                                  ]);
                                }).toList(),
                              ),
                            ),
                          ),
                        ),
                      ),
                      SizedBox(height: 16),
                      paginationWidget(context, currentPage: currentPage,
                          totalPage: totalPage,
                          perPage: perPage,
                          onUpdate: (currentPageVal, perPageVal) {
                            currentPage = currentPageVal;
                            perPage = perPageVal;
                            getUserApiCall();

                            setState(() {});
                          }),
                      SizedBox(height: 80),
                    ],
                  )
                ],
              ),
            ),
            appStore.isLoading
                ? loaderWidget()
                : lstAllUsers.isEmpty
                ? emptyWidget()
                : SizedBox(),
          ],
        ),
      );
    });
  }
}
// ListView.builder(
// shrinkWrap: true,
// itemCount: lstAllUsers.length,
// itemBuilder: (context, index) {
// return Padding(
// padding: const EdgeInsets.all(8.0),
// child: Container(
// decoration: BoxDecoration(
// color: Colors.grey.shade100,
// boxShadow: [BoxShadow(color: Colors.grey)],
// borderRadius: BorderRadius.all(
// Radius.circular(10),
// )),
// child: Padding(
// padding: const EdgeInsets.all(10.0),
// child: Column(
// mainAxisAlignment: MainAxisAlignment.start,
// crossAxisAlignment: CrossAxisAlignment.start,
// children: [
// RichText(
// text: TextSpan(text: 'Name : ', style: boldTextStyle(), children: [
// TextSpan(text: '${lstAllUsers[index].userName}', style: primaryTextStyle())
// ])),
// RichText(
// text: TextSpan(text: 'Latitude : ', style: boldTextStyle(), children: [
// TextSpan(text: '${lstAllUsers[index].lattitude}', style: primaryTextStyle())
// ])),
// RichText(
// text: TextSpan(text: 'Longitude : ', style: boldTextStyle(), children: [
// TextSpan(text: '${lstAllUsers[index].longtitude}', style: primaryTextStyle())
// ])),
// RichText(
// text: TextSpan(text: 'Mobile no : ', style: boldTextStyle(), children: [
// TextSpan(text: '${lstAllUsers[index].mono}', style: primaryTextStyle())
// ])),
// RichText(
// text: TextSpan(text: 'Address : ', style: boldTextStyle(), children: [
// TextSpan(text: '${lstAllUsers[index].address}', style: primaryTextStyle())
// ])),
// RichText(
// text: TextSpan(text: 'Country :', style: boldTextStyle(), children: [
// TextSpan(text: '${lstAllUsers[index].countryName}', style: primaryTextStyle())
// ])),
// ],
// ),
// ),
// ),
// );
// }),
