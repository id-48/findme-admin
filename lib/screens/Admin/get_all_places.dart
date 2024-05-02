import 'dart:convert';

import 'package:find_me_admin/models/places/res_get_all_place.dart';
import 'package:find_me_admin/utils/Extensions/int_extensions.dart';
import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:find_me_admin/components/AddButtonComponent.dart';
import 'package:find_me_admin/components/Admin/BodyCornerWidget.dart';
import 'package:find_me_admin/components/Admin/add_place_dialog.dart';
import 'package:find_me_admin/components/CommonConfirmationDialog.dart';
import 'package:find_me_admin/components/PaginationWidget.dart';
import 'package:find_me_admin/main.dart';
import 'package:find_me_admin/network/RestApis.dart';
import 'package:find_me_admin/utils/Colors.dart';
import 'package:find_me_admin/utils/Common.dart';
import 'package:find_me_admin/utils/Constants.dart';
import 'package:find_me_admin/utils/Extensions/constants.dart';
import 'package:find_me_admin/utils/Extensions/shared_pref.dart';
import 'package:find_me_admin/utils/Extensions/text_styles.dart';
import 'package:find_me_admin/utils/ResponsiveWidget.dart';
import 'package:find_me_admin/utils/toast.dart';
import 'package:hive/hive.dart';
import '../../models/user_model/res_get_all_user.dart';

class GetAllPlacesScreen extends StatefulWidget {
  static String route = '/admin/getAllPlaces';

  @override
  State<GetAllPlacesScreen> createState() => _GetAllPlacesScreenState();
}

class _GetAllPlacesScreenState extends State<GetAllPlacesScreen> {
  ScrollController horizontalScrollController = ScrollController();

  int currentPage = 1;
  int totalPage = 1;
  var perPage = 10;
  List<AllUser> lstAllUsers = [];
  List<Place> lstPlaceData = [];
  bool isLoading = false;
  late Box<dynamic> hiveBox;

  @override
  void initState() {
    init();
    super.initState();
  }

  Future<void> init() async {
    // hiveBox = await HiveManager.instance.openHiveBox('PLACE');

    appStore.setSelectedMenuIndex(get_all_places);
    getAllPlacesApiCall();
    getUserApiCall();
  }

  getAllPlacesApiCall() async {
    await getAllPlaces(limit: perPage, page: currentPage).then((value) {
      if (value.status == true) {
        lstPlaceData = value.place;
        setState(() {});
      }
    });
  }

  Future<List<Place>> getUserWisePlaceApiCall(String mono) async {
    List<Place> lstPlace = [];

    await getUserWisePlaces(limit: perPage, page: currentPage, mono: mono).then((value) {
      if (value.status == true) {
        print('=======================> ${value.places}');
        lstPlace = value.places;
        return value.places;
      } else {}
      return lstPlace;
    });
    return lstPlace;
  }

  getUserApiCall() async {
    await getAllUsers(limit: perPage, page: currentPage).then((value) {
      if (value.status == true) {
        print('lstAllUsers ::${lstAllUsers}');
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
    Widget addColorsButton() {
      return AddButtonComponent("Add Places", () {
        showDialog(
          context: context,
          barrierDismissible: false,
          builder: (BuildContext dialogContext) {
            return AddPlacesDialog();
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
                  ResponsiveWidget.isSmallScreen(context) && appStore.isMenuExpanded
                      ? Wrap(
                          spacing: 16,
                          runSpacing: 16,
                          crossAxisAlignment: WrapCrossAlignment.center,
                          children: [
                            Text("Places", style: boldTextStyle(size: 20, color: primaryColor)),
                            // addColorsButton(),
                          ],
                        )
                      : Row(
                          mainAxisAlignment: MainAxisAlignment.spaceBetween,
                          children: [
                            Text("Places", style: boldTextStyle(size: 20, color: primaryColor)),
                            addColorsButton(),
                          ],
                        ),
                  Column(
                    children: [
                      SizedBox(height: 16),
                      Container(
                        decoration: BoxDecoration(
                            // color: Colors.white,
                            color: primaryColor.withOpacity(0.1),
                            borderRadius: BorderRadius.circular(defaultRadius),
                            // boxShadow: commonBoxShadow()
                        ),
                        child: Column(
                          children: [
                            Padding(
                              padding: const EdgeInsets.only(left: 50, right: 50, top: 10, bottom: 10),
                              child: Row(
                                // mainAxisAlignment: MainAxisAlignment.spaceBetween,
                                children: [
                                  SizedBox(
                                      width: 500,
                                      child: Text("Name", style: boldTextStyle(size: 15, color: primaryColor))),
                                  SizedBox(
                                      width: 380,
                                      child: Text("Mobile No", style: boldTextStyle(size: 15, color: primaryColor))),
                                  SizedBox(
                                      width: 380,
                                      child: Text("Gender", style: boldTextStyle(size: 15, color: primaryColor))),
                                  SizedBox(
                                      width: 200,
                                      child: Text("CountryCode", style: boldTextStyle(size: 15, color: primaryColor))),
                                ],
                              ),
                            ),
                            ListView.builder(
                                shrinkWrap: true,
                                itemCount: lstAllUsers.length,
                                itemBuilder: (context, index) {
                                  return Padding(
                                    padding: const EdgeInsets.all(5),
                                    child: Card(
                                        elevation: 0.1,
                                        shadowColor: Colors.black,
                                        color: Colors.white,
                                        child: Padding(
                                            padding: const EdgeInsets.all(5),
                                            child: ExpansionTile(
                                              onExpansionChanged: (value) async {},
                                              backgroundColor: Colors.white,
                                              title: createCollapsedColumn(index, lstAllUsers[index]),
                                              trailing: SizedBox(),
                                              children: [createExpandedColumn(lstAllUsers[index].mono)],
                                            ))),
                                  );
                                }),
                          ],
                        ),
                      ),
                      SizedBox(height: 16),
                      paginationWidget(context, currentPage: currentPage, totalPage: totalPage, perPage: perPage,
                          onUpdate: (currentPageVal, perPageVal) {
                        currentPage = currentPageVal;
                        perPage = perPageVal;
                        getAllPlacesApiCall();

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

  Widget createCollapsedColumn(int index, AllUser userData) {
    return Row(
      mainAxisAlignment: MainAxisAlignment.spaceBetween,
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        SizedBox(
          width: 300,
          child: Text(
            userData.name,
            style: boldTextStyle(),
          ),
        ),
        SizedBox(
          width: 200,
          child: Text(
            userData.mono,
            style: boldTextStyle(),
          ),
        ),
        SizedBox(
          width: 200,
          child: Text(
            userData.gender,
            style: boldTextStyle(),
          ),
        ),
        SizedBox(
          width: 200,
          child: Text(
            userData.countryCode,
            style: boldTextStyle(),
          ),
        )
      ],
    );
  }

  Widget createExpandedColumn(String mono) {
    print('mono :::${mono}');
    // lstPlace = hiveBox.getAt(index) ?? [];
    // print(' index $index lstPlace ::${lstPlace.toList()}');
    return Column(
      mainAxisAlignment: MainAxisAlignment.start,
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        SizedBox(
          height: 10,
        ),
        Padding(
          padding: const EdgeInsets.only(left: 20),
          child: Text("Places", style: boldTextStyle(size: 20, color: primaryColor)),
        ),
        SizedBox(
          height: 10,
        ),
        FutureBuilder<List<Place>>(
            future: getUserWisePlaceApiCall(mono),
            builder: (context, snapshot) {
              List<Place> lstPlace = snapshot.data ?? [];

              if (lstPlace.isNotEmpty) {
                return ConstrainedBox(
                  constraints: BoxConstraints(minWidth: getBodyWidth(context) - 48),
                  child: DataTable(
                    dataRowHeight: 45,
                    headingRowHeight: 45,
                    horizontalMargin: 16,
                    headingRowColor: MaterialStateColor.resolveWith((states) => textSecondaryColor.withOpacity(0.1)),
                    showCheckboxColumn: false,
                    dataTextStyle: primaryTextStyle(size: 14),
                    headingTextStyle: boldTextStyle(),
                    columns: [
                      DataColumn(label: Text("No")),
                      DataColumn(label: Text("Name")),
                      DataColumn(label: Text("Address")),
                      DataColumn(label: Text("Category")),
                      DataColumn(label: Text("Location WithIn")),
                      DataColumn(label: Text("Description")),
                      DataColumn(label: Text("Edit")),
                    ],
                    rows: lstPlace.map((mData) {
                      return DataRow(cells: [
                        DataCell(Text("${lstPlace.indexOf(mData) + 1}")),
                        DataCell(Text(mData.placeName)),
                        DataCell(Text(mData.location)),
                        DataCell(Text(mData.category)),
                        DataCell(Text(mData.locatedWithin)),
                        DataCell(Text(mData.placeDescription)),
                        DataCell(
                          Row(
                            children: [
                              Row(
                                children: [
                                  outlineActionIcon(Icons.edit, Colors.green, "Edit", () {
                                    showDialog(
                                        context: context,
                                        barrierDismissible: false,
                                        builder: (BuildContext dialogContext) {
                                          print('mData ::${mData.toJson()}');
                                          return AddPlacesDialog(
                                            placeData: mData,
                                            onUpdate: () {},
                                          );
                                        });
                                  }),
                                  SizedBox(width: 8),
                                ],
                              ),
                              outlineActionIcon(Icons.delete, Colors.red, "Delete", () {
                                commonConfirmationDialog(context, DIALOG_TYPE_DELETE, () {
                                  if (getStringAsync(USER_TYPE) == DEMO_ADMIN) {
                                    ToastUtils.showCustomToast(
                                        context, "Are you sure you want to delete data", "warning");
                                  } else {
                                    deletePlaces(placeId: mData.id).then((value) {
                                      if (value.status == true) {
                                        ToastUtils.showCustomToast(context, value.message, "success");

                                        Navigator.pushNamed(context, GetAllPlacesScreen.route);
                                      } else {
                                        ToastUtils.showCustomToast(context, value.message, "warning");
                                      }
                                    });
                                  }
                                },
                                    isForceDelete: mData.updatedAt != "",
                                    title: "Delete data",
                                    subtitle: "Are you sure you want to delete Showroom?");
                              }),
                            ],
                          ),
                        ),
                      ]);
                    }).toList(),
                  ),
                );
              } else if (lstPlace.isEmpty) {
                return Padding(
                  padding: const EdgeInsets.only(bottom: 20),
                  child: Container(
                    child: Center(
                      child: Text(
                        'No Places Found!',
                        style: primaryTextStyle(),
                      ),
                    ),
                  ),
                );
              }
              return CircularProgressIndicator(
                color: primaryColor,
              );
            }),
      ],
    );
  }
}
