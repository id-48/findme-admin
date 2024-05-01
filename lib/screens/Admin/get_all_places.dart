import 'package:find_me_admin/models/places/res_get_all_place.dart';
import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:find_me_admin/components/AddButtonComponent.dart';
import 'package:find_me_admin/components/Admin/BodyCornerWidget.dart';
import 'package:find_me_admin/components/Admin/add_place_dialog.dart';
import 'package:find_me_admin/components/CommonConfirmationDialog.dart';
import 'package:find_me_admin/components/PaginationWidget.dart';
import 'package:find_me_admin/main.dart';
import 'package:find_me_admin/models/designing/get_designing/res_desinging.dart';
import 'package:find_me_admin/network/RestApis.dart';
import 'package:find_me_admin/utils/Colors.dart';
import 'package:find_me_admin/utils/Common.dart';
import 'package:find_me_admin/utils/Constants.dart';
import 'package:find_me_admin/utils/Extensions/constants.dart';
import 'package:find_me_admin/utils/Extensions/shared_pref.dart';
import 'package:find_me_admin/utils/Extensions/text_styles.dart';
import 'package:find_me_admin/utils/ResponsiveWidget.dart';
import 'package:find_me_admin/utils/toast.dart';

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

  List<Place> lstPlaceData = [];

  @override
  void initState() {
    init();
    super.initState();
  }

  Future<void> init() async {
    appStore.setSelectedMenuIndex(get_all_places);
    getAllPlacesApiCall();
  }

  getAllPlacesApiCall() async {
    await getAllPlaces(limit: perPage, page: currentPage).then((value) {
      if (value.status == true) {
        lstPlaceData = value.place;
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

                  ResponsiveWidget.isSmallScreen(context) &&
                      appStore.isMenuExpanded
                      ? Wrap(
                    spacing: 16,
                    runSpacing: 16,
                    crossAxisAlignment: WrapCrossAlignment.center,
                    children: [
                      Text("Add Places", style: boldTextStyle(size: 20,
                          color: primaryColor)),
                      // addColorsButton(),
                    ],
                  )
                      : Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      Text("Add Places", style: boldTextStyle(size: 20,
                          color: primaryColor)),
                      addColorsButton(),
                    ],
                  ),
                  Column(
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
                                  DataColumn(label: Text("Place Name")),
                                  DataColumn(label: Text("Category")),
                                  DataColumn(label: Text("Mo.no")),
                                  DataColumn(label: Text("Location")),
                                  DataColumn(label: Text("Latitude")),
                                  DataColumn(label: Text("Longitude")),
                                  DataColumn(label: Text("Located Within")),
                                  DataColumn(label: Text("Place Description")),
                                  DataColumn(label: Text("Action")),
                                ],
                                rows: lstPlaceData.map((mData) {
                                  return DataRow(cells: [
                                    DataCell(Text(
                                        "${lstPlaceData.indexOf(mData) + 1}")),
                                    DataCell(Text(mData.placeName)),
                                    DataCell(Text(mData.category)),
                                    DataCell(Text(mData.mono)),
                                    DataCell(Text(mData.location)),
                                    DataCell(Text(mData.lattitued)),
                                    DataCell(Text(mData.longtitude)),
                                    DataCell(Text(mData.locatedWithin)),
                                    DataCell(Text(mData.placeDescription)),
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
                                                      return AddPlacesDialog(
                                                        placeData: mData,
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
                                                    deletePlaces(
                                                        placeId: mData.id)
                                                        .then((value) {
                                                      if (value.status ==
                                                          true) {
                                                        ToastUtils
                                                            .showCustomToast(
                                                            context,
                                                            value.message,
                                                            "success");

                                                        Navigator.pushNamed(
                                                            context,
                                                            GetAllPlacesScreen
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
                                                subtitle: "Are you sure you want to delete Designing?");
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
                : lstPlaceData.isEmpty
                ? emptyWidget()
                : SizedBox(),
          ],
        ),
      );
    });
  }
}
