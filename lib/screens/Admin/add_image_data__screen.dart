import 'package:find_me_admin/components/Admin/add_image_data_dialog.dart';
import 'package:find_me_admin/components/CommonConfirmationDialog.dart';
import 'package:find_me_admin/models/imageData/res_imageData.dart';
import 'package:find_me_admin/network/RestApis.dart';
import 'package:find_me_admin/utils/Constants.dart';
import 'package:find_me_admin/utils/Extensions/shared_pref.dart';
import 'package:find_me_admin/utils/Extensions/toast.dart';
import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';

import '../../components/AddButtonComponent.dart';
import '../../components/Admin/BodyCornerWidget.dart';
import '../../components/PaginationWidget.dart';
import '../../main.dart';
import '../../utils/Colors.dart';
import '../../utils/Common.dart';
import '../../utils/Extensions/constants.dart';
import '../../utils/Extensions/text_styles.dart';
import '../../utils/ResponsiveWidget.dart';

class ImageDataScreen extends StatefulWidget {
  static String route = '/admin/imageData';

  @override
  State<ImageDataScreen> createState() => _ImageDataScreenState();
}

class _ImageDataScreenState extends State<ImageDataScreen> {
  ScrollController horizontalScrollController = ScrollController();

  int totalData = 0;
  int currentPage = 1;
  int totalPage = 1;
  var perPage = 10;

  List<ImageDatum> imageList = [];

  @override
  void initState() {
    super.initState();
    init();
  }

  Future<void> init() async {
    appStore.setSelectedMenuIndex(add_imageData_index);
    await getImage();
    await totalPageValue();
  }

  getImage() async {
    await getImageData(limit: perPage, page: currentPage).then((value) {
      if (value.status == true) {
        totalData = value.totalImageData;
        imageList = value.imageData;
        setState(() {});
      }
    });
  }

  Future totalPageValue() async {
    totalPage = (totalData / perPage).ceil();
    print("total page -->>$totalPage");
    setState(() {});
  }

  @override
  void setState(fn) {
    if (mounted) super.setState(fn);
  }

  @override
  Widget build(BuildContext context) {
    Widget addImageDataButton() {
      return AddButtonComponent("Image Data", () {
        showDialog(
          context: context,
          barrierDismissible: false,
          builder: (BuildContext dialogContext) {
            return AddImageDataDialog();
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
                            Text("Image Data",
                                style: boldTextStyle(
                                    size: 20, color: primaryColor)),
                            addImageDataButton(),
                          ],
                        )
                      : Row(
                          mainAxisAlignment: MainAxisAlignment.spaceBetween,
                          children: [
                            Text("Image Data",
                                style: boldTextStyle(
                                    size: 20, color: primaryColor)),
                            addImageDataButton(),
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
                                dataRowHeight: 60,
                                headingRowHeight: 45,
                                horizontalMargin: 16,
                                headingRowColor: MaterialStateColor.resolveWith(
                                    (states) => primaryColor.withOpacity(0.1)),
                                showCheckboxColumn: false,
                                dataTextStyle: primaryTextStyle(size: 14),
                                headingTextStyle: boldTextStyle(),
                                columns: [
                                  DataColumn(label: Text("No.")),
                                  DataColumn(label: Text("Image Number")),
                                  DataColumn(label: Text("Image")),
                                  DataColumn(label: Text("Action")),
                                ],
                                rows: imageList.map((mData) {
                                  return DataRow(cells: [
                                    DataCell(Text(
                                        "${imageList.indexOf(mData) + 1}")),
                                    DataCell(Text(mData.imageNumber)),
                                    DataCell(Row(
                                      children: mData.image.length != 0
                                          ? [
                                              ...mData.image.map(
                                                (image) => Padding(
                                                  padding: const EdgeInsets.all(
                                                      10.0),
                                                  child: ClipRRect(
                                                      borderRadius:
                                                          BorderRadius.circular(
                                                              10),
                                                      child: commonCachedNetworkImage(
                                                          "${mBaseUrl + image}",
                                                          fit: BoxFit.fill,
                                                          height: 70,
                                                          width: 50)),
                                                ),
                                              )
                                            ]
                                          : [Text("None")],
                                    )),
                                    DataCell(
                                      Row(
                                        children: [
                                          Row(
                                            children: [
                                              outlineActionIcon(Icons.edit,
                                                  Colors.green, "Edit", () {
                                                showDialog(
                                                    context: context,
                                                    barrierDismissible: false,
                                                    builder: (BuildContext
                                                        dialogContext) {
                                                      return AddImageDataDialog(
                                                        imageData: mData,
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
                                              if (getStringAsync(USER_TYPE) ==
                                                  DEMO_ADMIN) {
                                                ToastUtils.showCustomToast(
                                                    context,
                                                    "Delete",
                                                    "warning");
                                              } else {
                                                deleteImageData(
                                                        imageId: mData.id)
                                                    .then((value) {
                                                  if (value.status == true) {
                                                    ToastUtils.showCustomToast(
                                                        context,
                                                        value.message,
                                                        "success");
                                                    Navigator.pushNamed(context,
                                                        ImageDataScreen.route);
                                                  } else {
                                                    ToastUtils.showCustomToast(
                                                        context,
                                                        value.message,
                                                        "warning");
                                                  }
                                                });

                                                setState(() {});
                                              }
                                            },
                                                isForceDelete:
                                                    mData.updatedAt != "",
                                                title: "Delete data",
                                                subtitle:
                                                    "Do you want to delete this Image data?");
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
                          onUpdate: (currentPageVal, perPageVal) async {
                        currentPage = currentPageVal;
                        perPage = perPageVal;
                        await getImage();
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
                : imageList.isEmpty
                    ? emptyWidget()
                    : SizedBox(),
          ],
        ),
      );
    });
  }
}
