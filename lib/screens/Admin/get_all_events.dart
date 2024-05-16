import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:find_me_admin/components/AddButtonComponent.dart';
import 'package:find_me_admin/components/Admin/BodyCornerWidget.dart';
import 'package:find_me_admin/components/Admin/add_event_dialog.dart';
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
import 'package:intl/intl.dart';
import '../../models/event/get_user_wise_event/res_get_user_wise_event.dart';
import '../../models/user_model/get_user_profile.dart';
import '../../models/user_model/res_get_all_user.dart';

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
  List<User> lstAllUsers = [];
  int totalData = 0;

  // List<Event> lstAllEventData = [];

  @override
  void initState() {
    init();
    super.initState();
  }

  Future<void> init() async {
    appStore.setSelectedMenuIndex(get_all_event);
    // getAllEventsApi();
    await getUserApiCall();
    await totalPageValue();
  }

  Future<List<Event>> getUserWiseEventApiCall(String mono) async {
    List<Event> lstEvents = [];

    await getUserWiseEvent(limit: perPage, page: currentPage, mono: mono).then((value) {
      if (value.status == true) {
        lstEvents = value.events;
        return value.events;
      } else {}
      return lstEvents;
    });
    return lstEvents;
  }

  getUserApiCall() async {
    await getAllUsers(limit: perPage, page: currentPage).then((value) {
      if (value.status == true) {
        if (value.user != null) {
          lstAllUsers = value.user!;
          totalData = value.totalUser;
        }
        setState(() {});
      }
    });
  }

  Future totalPageValue() async {
    totalPage = (totalData / perPage).ceil();
    setState(() {});
  }

  // getAllEventsApi() async {
  //   await getAllEvents(limit: perPage, page: currentPage).then((value) {
  //     if (value.status == true) {
  //       lstAllEventData = value.event;
  //       setState(() {});
  //     }
  //   });
  // }

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
                  ResponsiveWidget.isSmallScreen(context) && appStore.isMenuExpanded
                      ? Wrap(
                          spacing: 16,
                          runSpacing: 16,
                          crossAxisAlignment: WrapCrossAlignment.center,
                          children: [
                            Text("Add Event", style: boldTextStyle(size: 20, color: primaryColor)),
                            addColorsButton(),
                          ],
                        )
                      : Row(
                          mainAxisAlignment: MainAxisAlignment.spaceBetween,
                          children: [
                            Text("Add Event", style: boldTextStyle(size: 20, color: primaryColor)),
                            addColorsButton(),
                          ],
                        ),
                  Column(
                    children: [
                      SizedBox(height: 16),
                      Container(
                        decoration: BoxDecoration(
                          // color: Colors.white,
                          borderRadius: BorderRadius.circular(defaultRadius),
                          color: primaryColor.withOpacity(0.1),

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
                                      child: Text("Country Name", style: boldTextStyle(size: 15, color: primaryColor))),
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
                          onUpdate: (currentPageVal, perPageVal) async {
                        currentPage = currentPageVal;
                        perPage = perPageVal;
                        await getUserApiCall();
                        await totalPageValue();

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

  Widget createCollapsedColumn(int index, User userData) {
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
            userData.countryName,
            style: boldTextStyle(),
          ),
        )
      ],
    );
  }

  Widget createExpandedColumn(String mono) {
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
          child: Text("Events", style: boldTextStyle(size: 20, color: primaryColor)),
        ),
        SizedBox(
          height: 10,
        ),
        FutureBuilder<List<Event>>(
            future: getUserWiseEventApiCall(mono),
            builder: (context, snapshot) {
              List<Event> lstEvent = snapshot.data ?? [];

              if (lstEvent.isNotEmpty) {
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
                      DataColumn(label: Text("Mobile No")),
                      DataColumn(label: Text("Time")),
                      DataColumn(label: Text("Latitude")),
                      DataColumn(label: Text("Longitude")),
                      DataColumn(label: Text("Location")),
                      DataColumn(label: Text("Event Data")),
                      DataColumn(label: Text("Description")),
                      DataColumn(label: Text("Edit")),
                    ],
                    rows: lstEvent.map((mData) {
                      return DataRow(cells: [
                        DataCell(Text("${lstEvent.indexOf(mData) + 1}")),
                        DataCell(Text(mData.title)),
                        DataCell(Text(mData.mono)),
                        DataCell(Text(mData.time)),
                        DataCell(Text(mData.lattitude)),
                        DataCell(Text(mData.longtitude)),
                        DataCell(Text(mData.location)),
                        DataCell(Text(DateFormat('dd/MM/yyyy').format(mData.eventDate))),
                        DataCell(Text(mData.description)),
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
                                          return AddEventDialog(
                                            event: mData,
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
                                    deleteEvents(eventId: mData.id).then((value) {
                                      if (value.status == true) {
                                        ToastUtils.showCustomToast(context, value.message, "success");

                                        Navigator.pushNamed(context, GetAllEventsScreen.route);
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
              } else if (lstEvent.isEmpty) {
                return Padding(
                  padding: const EdgeInsets.only(bottom: 20),
                  child: Container(
                    child: Center(
                      child: Text(
                        'No event found!',
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

// placeName
// category
// location
// lattitued
// longtitude
// locatedWithin
// placeDescription
// mono
