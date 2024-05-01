import 'dart:typed_data';
import 'package:file_selector/file_selector.dart';
import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:find_me_admin/components/AddButtonComponent.dart';
import 'package:find_me_admin/components/Admin/BodyCornerWidget.dart';
import 'package:find_me_admin/components/CommonConfirmationDialog.dart';
import 'package:find_me_admin/components/PaginationWidget.dart';
import 'package:find_me_admin/main.dart';
import 'package:find_me_admin/models/billing/get_billing/res_billing_data.dart';
import 'package:find_me_admin/network/RestApis.dart';
import 'package:find_me_admin/screens/Admin/add_billing_data__screen.dart';
import 'package:find_me_admin/screens/Admin/genrate_pdf.dart';
import 'package:find_me_admin/utils/Colors.dart';
import 'package:find_me_admin/utils/Common.dart';
import 'package:find_me_admin/utils/Constants.dart';
import 'package:find_me_admin/utils/Extensions/constants.dart';
import 'package:find_me_admin/utils/Extensions/shared_pref.dart';
import 'package:find_me_admin/utils/Extensions/text_styles.dart';
import 'package:find_me_admin/utils/ResponsiveWidget.dart';
import 'package:find_me_admin/utils/toast.dart';

class GetBillingScreen extends StatefulWidget {
  static String route = '/admin/GetBilling';

  @override
  State<GetBillingScreen> createState() => _GetBillingScreenState();
}

class _GetBillingScreenState extends State<GetBillingScreen> {
  ScrollController horizontalScrollController = ScrollController();

  int currentPage = 1;
  int totalPage = 1;
  var perPage = 10;

  String userLogin = "";
  String showRoomId = "";
  Uint8List? uint8list;
  List<Billing> billingData = [];
  bool isLoading = false;

  @override
  void initState() {
    init();
    super.initState();
  }

  Future<void> init() async {
    appStore.setSelectedMenuIndex(get_billing_index);
    showRoomId = await getString("showroomId");
    userLogin = await getString("userLogin");
    if (userLogin == "admin") {
      print("userLogin:50 $userLogin");
      getBillingApiCall();
    } else if (userLogin == "showRoom") {
      print("userLogin: $userLogin");
      getShowroomWiseApiCall();
    }
  }

  getBillingApiCall() async {
    await getBilling(limit: perPage, page: currentPage).then((value) {
      if (value.status == true) {
        billingData = value.billing;
        setState(() {});
      }
    });
  }

  getShowroomWiseApiCall() async {
    await getShowroomWiseBilling(
        limit: perPage, page: currentPage, showroomId: showRoomId).then((
        value) {
      if (value.status == true) {
        billingData = value.billing;
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
    Widget addBillingButton() {
      return AddButtonComponent("Add Billing Data", () {
        Navigator.pushNamed(context, BillingDataScreen.route);
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
                      Text("Billing Data", style: boldTextStyle(size: 20,
                          color: primaryColor)),
                      addBillingButton(),
                    ],
                  )
                      : Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      Text("Billing Data", style: boldTextStyle(size: 20,
                          color: primaryColor)),
                      addBillingButton(),
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
                                  DataColumn(label: Text("Bill No")),
                                  DataColumn(label: Text("Billing Date")),
                                  DataColumn(label: Text("Show Room Name")),
                                  DataColumn(label: Text("Name")),
                                  DataColumn(label: Text("Address")),
                                  DataColumn(label: Text("Delivery Date")),
                                  DataColumn(label: Text("Instruction")),
                                  DataColumn(label: Text("Mobile No")),
                                  DataColumn(label: Text("Total")),
                                  DataColumn(label: Text("Payment Type")),
                                  DataColumn(label: Text("Advance Cash")),
                                  DataColumn(label: Text("Remaining Cash")),
                                  DataColumn(label: Text("Action")),
                                ],
                                rows: billingData.map((mData) {
                                  return DataRow(cells: [
                                    DataCell(Text(
                                        "${billingData.indexOf(mData) + 1}")),
                                    DataCell(Text(mData.billNo)),
                                    DataCell(Text(mData.billingDate)),
                                    DataCell(Text(mData.branchName)),
                                    DataCell(Text(mData.name)),
                                    DataCell(Text(mData.address)),
                                    DataCell(Text(mData.deliveryDate)),
                                    DataCell(Text(mData.instruction)),
                                    DataCell(Text(mData.mobileNo)),
                                    DataCell(Text(mData.total.toString())),
                                    DataCell(Text(mData.paymentType)),
                                    DataCell(
                                        Text(mData.advanceCash.toString())),
                                    DataCell(
                                        Text(mData.remaingCash.toString())),
                                    DataCell(
                                      Row(
                                        children: [
                                          Row(
                                            children: [
                                              outlineActionIcon(
                                                  Icons.edit, Colors.green,
                                                  "Edit", () {
                                                Navigator.pushNamed(context,
                                                    BillingDataScreen.route,
                                                    arguments: {
                                                      "mData": mData
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
                                                        context, "Delete Data",
                                                        "warning");
                                                  } else {
                                                    deleteBilling(
                                                        billingId: mData.id)
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
                                                            GetBillingScreen
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
                                                subtitle: "Are you sure you want to delete Billing data?");
                                          }),
                                          SizedBox(width: 8),
                                          outlineActionIcon(
                                              Icons.download_for_offline,
                                              Colors.blue, "Pdf Download",
                                                  () async {
                                                try {
                                                  isLoading = true;
                                                  setState(() {});
                                                  uint8list =
                                                  await PdfGeneratorView()
                                                      .generateInvoice(mData);
                                                } catch (e) {} finally {
                                                  isLoading = false;
                                                  setState(() {});
                                                  await Future.delayed(Duration(
                                                      milliseconds: 1000));
                                                  if (uint8list != null) {
                                                    const String fileName = 'Billing.pdf';
                                                    final FileSaveLocation? result =
                                                    await getSaveLocation(
                                                        suggestedName: fileName);
                                                    if (result == null) {
                                                      // Operation was canceled by the user.
                                                      return;
                                                    }

                                                    const String mimeType = 'pdf';
                                                    final XFile textFile =
                                                    XFile.fromData(uint8list!,
                                                        mimeType: mimeType,
                                                        name: fileName);
                                                    await textFile.saveTo(
                                                        result.path);
                                                    // print(path);
                                                    print(
                                                        'Download pdf successfully.....');
                                                    ToastUtils.showCustomToast(
                                                        context,
                                                        "PDF Download Successfully",
                                                        "success");
                                                  } else {
                                                    ToastUtils.showCustomToast(
                                                        context,
                                                        "Something want wrong!",
                                                        "warning");
                                                  }
                                                }
                                              }),
                                          // SizedBox(width: 8),
                                          // isLoading
                                          //     ? CircularProgressIndicator()
                                          //     : outlineActionIcon(Icons.download_for_offline, Colors.blue, "Pdf Download", () async {
                                          //         if (uint8list != null) {
                                          //           // Directory directory = await getApplicationDocumentsDirectory();
                                          //           // String path = directory.path;
                                          //           //Create the empty file.
                                          //           // File file = File('$path/${'sample.pdf'}');
                                          //           //Write the PDF data retrieved from the SfPdfViewer.
                                          //           // await file.writeAsBytes(uint8lint!, flush: true);
                                          //           const String fileName = 'Billing.pdf';
                                          //           final FileSaveLocation? result = await getSaveLocation(suggestedName: fileName);
                                          //           if (result == null) {
                                          //             // Operation was canceled by the user.
                                          //             return;
                                          //           }
                                          //
                                          //           const String mimeType = 'pdf';
                                          //           final XFile textFile = XFile.fromData(uint8list!, mimeType: mimeType, name: fileName);
                                          //           await textFile.saveTo(result.path);
                                          //           // print(path);
                                          //           print('Download successfully.....');
                                          //         }
                                          //       }),
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
                            getBillingApiCall();

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
                : billingData.isEmpty
                ? emptyWidget()
                : SizedBox(),
          ],
        ),
      );
    });
  }
}
