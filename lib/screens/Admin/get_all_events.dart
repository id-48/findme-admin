import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:find_me_admin/components/AddButtonComponent.dart';
import 'package:find_me_admin/components/Admin/BodyCornerWidget.dart';
import 'package:find_me_admin/components/Admin/add_event_dialog.dart';
import 'package:find_me_admin/components/CommonConfirmationDialog.dart';
import 'package:find_me_admin/components/PaginationWidget.dart';
import 'package:find_me_admin/main.dart';
import 'package:find_me_admin/models/colors/get_colors/res_colors.dart';
import 'package:find_me_admin/network/RestApis.dart';
import 'package:find_me_admin/utils/Colors.dart';
import 'package:find_me_admin/utils/Common.dart';
import 'package:find_me_admin/utils/Constants.dart';
import 'package:find_me_admin/utils/Extensions/constants.dart';
import 'package:find_me_admin/utils/Extensions/shared_pref.dart';
import 'package:find_me_admin/utils/Extensions/text_styles.dart';
import 'package:find_me_admin/utils/ResponsiveWidget.dart';
import 'package:find_me_admin/utils/toast.dart';

import '../../models/event/res_get_all_event.dart';

class GetAllEventsScreen extends StatefulWidget {
  static String route = '/admin/AddColors';

  @override
  State<GetAllEventsScreen> createState() => _GetAllEventsScreenState();
}

class _GetAllEventsScreenState extends State<GetAllEventsScreen> {
  ScrollController horizontalScrollController = ScrollController();

  int currentPage = 1;
  int totalPage = 1;
  var perPage = 10;

  List<Event> lstAllEventData = [];

  @override
  void initState() {
    init();
    super.initState();
  }

  Future<void> init() async {
    appStore.setSelectedMenuIndex(get_all_event);
    getAllEventsApi();
  }

  getAllEventsApi() async {
    await getAllEvents(limit: perPage, page: currentPage).then((value) {
      if (value.status == true) {
        lstAllEventData = value.event;
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
      return AddButtonComponent("Add Event", () {
        showDialog(
          context: context,
          barrierDismissible: false,
          builder: (BuildContext dialogContext) {
            return AddEventDialog();
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
                      Text("Add Event",
                          style: boldTextStyle(
                              size: 20, color: primaryColor)),
                      addColorsButton(),
                    ],
                  )
                      : Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      Text("Add Event",
                          style: boldTextStyle(
                              size: 20, color: primaryColor)),
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
                                  DataColumn(label: Text("Title")),
                                  DataColumn(label: Text("Description")),
                                  DataColumn(label: Text("Mobile no")),
                                  DataColumn(label: Text("Latitude")),
                                  DataColumn(label: Text("Longitude")),
                                  DataColumn(label: Text("Time")),
                                  DataColumn(label: Text("Address")),
                                  DataColumn(label: Text("Action")),
                                ],
                                rows: lstAllEventData.map((mData) {
                                  return DataRow(cells: [
                                    DataCell(Text(
                                        "${lstAllEventData.indexOf(mData) +
                                            1}")),
                                    DataCell(Text(mData.title)),
                                    DataCell(Text(mData.description)),
                                    DataCell(Text(mData.mono)),
                                    DataCell(Text(mData.lattitude)),
                                    DataCell(Text(mData.longtitude)),
                                    DataCell(Text(mData.time)),
                                    DataCell(Text(mData.location)),
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
                                                    builder: (BuildContext
                                                    dialogContext) {
                                                      return AddEventDialog(
                                                        event: mData,
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
                                                    deleteEvents(
                                                        eventId: mData.id)
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
                                                            GetAllEventsScreen
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
                                                subtitle: "Are you sure you want to delete Color?");
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
                            getAllEventsApi();

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
                : lstAllEventData.isEmpty
                ? emptyWidget()
                : SizedBox(),
          ],
        ),
      );
    });
  }
}
// placeName
// category
// location
// lattitued
// longtitude
// locatedWithin
// placeDescription
// mono