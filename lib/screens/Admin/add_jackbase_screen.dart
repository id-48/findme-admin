import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:find_me_admin/components/AddButtonComponent.dart';
import 'package:find_me_admin/components/Admin/BodyCornerWidget.dart';
import 'package:find_me_admin/components/Admin/add_jackbase_dialog.dart';
import 'package:find_me_admin/components/CommonConfirmationDialog.dart';
import 'package:find_me_admin/components/PaginationWidget.dart';
import 'package:find_me_admin/main.dart';
import 'package:find_me_admin/models/jackbase/get_jackbase/res_jackbase.dart';
import 'package:find_me_admin/network/RestApis.dart';
import 'package:find_me_admin/utils/Colors.dart';
import 'package:find_me_admin/utils/Common.dart';
import 'package:find_me_admin/utils/Constants.dart';
import 'package:find_me_admin/utils/Extensions/constants.dart';
import 'package:find_me_admin/utils/Extensions/shared_pref.dart';
import 'package:find_me_admin/utils/Extensions/text_styles.dart';
import 'package:find_me_admin/utils/ResponsiveWidget.dart';
import 'package:find_me_admin/utils/toast.dart';


class AddJackBaseScreen extends StatefulWidget {
  static String route = '/admin/AddJackBase';

  @override
  State<AddJackBaseScreen> createState() => _AddJackBaseScreenState();
}

class _AddJackBaseScreenState extends State<AddJackBaseScreen> {
  ScrollController horizontalScrollController = ScrollController();

  int currentPage = 1;
  int totalPage = 1;
  var perPage = 10;

  List<JackBase> jackBaseData = [];

  @override
  void initState() {
    init();
    super.initState();
  }

  Future<void> init() async {
    appStore.setSelectedMenuIndex(add_jackbase_index);
    getJackBaseApiCall();
  }

  getJackBaseApiCall() async {
    await getJackBase(limit: perPage, page: currentPage).then((value) {
      if (value.status == true) {
        jackBaseData = value.jackBase;
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
    Widget addJackBaseButton() {
      return AddButtonComponent("Add Jack and Base", () {
        showDialog(
          context: context,
          barrierDismissible: false,
          builder: (BuildContext dialogContext) {
            return AddJackBaseDialog();
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
                      Text("Add Jack & Base",
                          style: boldTextStyle(
                              size: 20, color: primaryColor)),
                      addJackBaseButton(),
                    ],
                  )
                      : Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      Text("Add Jack & Base",
                          style: boldTextStyle(
                              size: 20, color: primaryColor)),
                      addJackBaseButton(),
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
                              borderRadius:
                              BorderRadius.circular(defaultRadius),
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
                                headingRowColor: MaterialStateColor.resolveWith(
                                        (states) =>
                                        primaryColor.withOpacity(0.1)),
                                showCheckboxColumn: false,
                                dataTextStyle: primaryTextStyle(size: 14),
                                headingTextStyle: boldTextStyle(),
                                columns: [
                                  DataColumn(label: Text("No")),
                                  DataColumn(label: Text("Jack & Base")),
                                  DataColumn(label: Text("Action")),
                                ],
                                rows: jackBaseData.map((mData) {
                                  return DataRow(cells: [
                                    DataCell(Text(
                                        "${jackBaseData.indexOf(mData) + 1}")),
                                    DataCell(Text(mData.jackBase)),
                                    DataCell(
                                      Row(
                                        children: [
                                          Row(
                                            children: [
                                              outlineActionIcon(
                                                  Icons.edit,
                                                  Colors.green, "Edit", () {
                                                showDialog(
                                                    context: context,
                                                    barrierDismissible: false,
                                                    builder: (BuildContext
                                                    dialogContext) {
                                                      return AddJackBaseDialog(
                                                        jackBaseData: mData,
                                                        onUpdate: () {},
                                                      );
                                                    });
                                              }),
                                              SizedBox(width: 8),
                                            ],
                                          ),
                                          outlineActionIcon(Icons.delete,
                                              Colors.red, "Delete", () {
                                                commonConfirmationDialog(
                                                    context, DIALOG_TYPE_DELETE,
                                                        () {
                                                      if (getStringAsync(
                                                          USER_TYPE) ==
                                                          DEMO_ADMIN) {
                                                        ToastUtils
                                                            .showCustomToast(
                                                            context,
                                                            "Are you sure you want to delete data",
                                                            "warning");
                                                      } else {
                                                        deleteJackBase(
                                                            jackBaseId: mData
                                                                .id)
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
                                                                AddJackBaseScreen
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
                                                    isForceDelete:
                                                    mData.updatedAt != "",
                                                    title: "Delete data",
                                                    subtitle:
                                                    "Are you sure you want to delete Jack base?");
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
                      paginationWidget(context,
                          currentPage: currentPage,
                          totalPage: totalPage,
                          perPage: perPage,
                          onUpdate: (currentPageVal, perPageVal) {
                            currentPage = currentPageVal;
                            perPage = perPageVal;
                            getJackBaseApiCall();

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
                : jackBaseData.isEmpty
                ? emptyWidget()
                : SizedBox(),
          ],
        ),
      );
    });
  }
}
