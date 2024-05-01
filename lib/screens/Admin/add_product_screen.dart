import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:find_me_admin/components/AddButtonComponent.dart';
import 'package:find_me_admin/components/Admin/add_product_dialog.dart';
import 'package:find_me_admin/components/CommonConfirmationDialog.dart';
import 'package:find_me_admin/models/product/get_product/res_get_product.dart';
import 'package:find_me_admin/network/RestApis.dart';
import 'package:find_me_admin/utils/Constants.dart';
import 'package:find_me_admin/utils/Extensions/shared_pref.dart';
import 'package:find_me_admin/utils/Extensions/toast.dart';

import '../../components/Admin/BodyCornerWidget.dart';
import '../../components/PaginationWidget.dart';
import '../../main.dart';
import '../../utils/Colors.dart';
import '../../utils/Common.dart';
import '../../utils/Extensions/constants.dart';
import '../../utils/Extensions/text_styles.dart';
import '../../utils/ResponsiveWidget.dart';

class AddProductScreen extends StatefulWidget {
  static String route = '/admin/ProductScreen';

  @override
  State<AddProductScreen> createState() => _AddProductScreenState();
}

class _AddProductScreenState extends State<AddProductScreen> {
  ScrollController horizontalScrollController = ScrollController();

  int totalData = 0;

  int currentPage = 1;
  int totalPage = 1;
  int perPage = 10;

  List<ProductData> productList = [];

  @override
  void initState() {
    super.initState();
    init();
  }

  Future<void> init() async {
    appStore.setSelectedMenuIndex(add_product_index);
    await getProductList();
    await totalPageValue();
  }

  Future getProductList() async {
    await getProduct(limit: perPage, page: currentPage).then((value) {
      if (value.status == true) {
        totalData = value.totalProduct;
        productList = value.product ?? [];
        setState(() {});
      }
    });
  }

  Future totalPageValue() async {
    totalPage = (totalData / perPage).ceil();
    setState(() {});
  }

  @override
  void setState(fn) {
    if (mounted) super.setState(fn);
  }

  @override
  Widget build(BuildContext context) {
    Widget addProductButton() {
      return AddButtonComponent("Product", () {
        showDialog(
          context: context,
          barrierDismissible: false,
          builder: (BuildContext dialogContext) {
            return AddProductDialog();
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
                      Text("Product",
                          style: boldTextStyle(
                              size: 20, color: primaryColor)),
                      addProductButton(),
                    ],
                  )
                      : Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      Text("Product",
                          style: boldTextStyle(
                              size: 20, color: primaryColor)),
                      addProductButton(),
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
                                        (states) =>
                                        primaryColor.withOpacity(0.1)),
                                showCheckboxColumn: false,
                                dataTextStyle: primaryTextStyle(size: 14),
                                headingTextStyle: boldTextStyle(),
                                columns: [
                                  DataColumn(label: Text("No")),
                                  DataColumn(label: Text("Product Name")),
                                  DataColumn(label: Text("Product Image")),
                                  DataColumn(
                                      label: Text("Product Image Number")),
                                  DataColumn(label: Text("Colors")),
                                  DataColumn(label: Text("Designing")),
                                  DataColumn(label: Text("Foot Rest")),
                                  DataColumn(label: Text("Jack And Base")),
                                  DataColumn(label: Text("Action")),
                                ],
                                rows: productList.map((mData) {
                                  return DataRow(cells: [
                                    DataCell(Text(
                                        "${productList.indexOf(mData) + 1}")),
                                    DataCell(Text("${mData.productName}")),
                                    DataCell(Padding(
                                      padding: const EdgeInsets.all(10.0),
                                      child: ClipRRect(
                                          borderRadius:
                                          BorderRadius.circular(10),
                                          child: mData.image == "NA"
                                              ? Container(
                                              color: Color(0xffeeeeee),
                                              height: 70,
                                              width: 50)
                                              : commonCachedNetworkImage(
                                              "${mBaseUrl + mData.image}",
                                              fit: BoxFit.fill,
                                              height: 70,
                                              width: 50)),
                                    )),
                                    DataCell(Text(mData.imageNumber)),
                                    DataCell(Row(
                                      children: [
                                        for (int i = 0;
                                        i < mData.colors.length;
                                        i++)
                                          Padding(
                                            padding: const EdgeInsets.all(8.0),
                                            child: Container(
                                              child: Padding(
                                                  padding:
                                                  const EdgeInsets.all(10),
                                                  child: Text(
                                                    mData.colors[i].toString(),
                                                    style: TextStyle(
                                                        fontWeight:
                                                        FontWeight.w300,
                                                        color: Colors.black),
                                                  )),
                                              decoration: BoxDecoration(
                                                  color: primaryColor
                                                      .withOpacity(0.1),
                                                  borderRadius:
                                                  BorderRadius.all(
                                                      Radius.circular(20))),
                                            ),
                                          ),
                                      ],
                                    )),
                                    DataCell(Row(
                                      children: [
                                        for (int i = 0;
                                        i < mData.designing.length;
                                        i++)
                                          Padding(
                                            padding: const EdgeInsets.all(8.0),
                                            child: Container(
                                              child: Padding(
                                                  padding:
                                                  const EdgeInsets.all(10),
                                                  child: Text(
                                                    mData.designing[i]
                                                        .toString(),
                                                    style: TextStyle(
                                                        fontWeight:
                                                        FontWeight.w300,
                                                        color: Colors.black),
                                                  )),
                                              decoration: BoxDecoration(
                                                  color: primaryColor
                                                      .withOpacity(0.1),
                                                  borderRadius:
                                                  BorderRadius.all(
                                                      Radius.circular(20))),
                                            ),
                                          ),
                                      ],
                                    )),
                                    DataCell(Row(
                                      children: [
                                        for (int i = 0;
                                        i < mData.footrest.length;
                                        i++)
                                          Padding(
                                            padding: const EdgeInsets.all(8.0),
                                            child: Container(
                                              child: Padding(
                                                  padding:
                                                  const EdgeInsets.all(10),
                                                  child: Text(
                                                    mData.footrest[i]
                                                        .toString(),
                                                    style: TextStyle(
                                                        fontWeight:
                                                        FontWeight.w300,
                                                        color: Colors.black),
                                                  )),
                                              decoration: BoxDecoration(
                                                  color: primaryColor
                                                      .withOpacity(0.1),
                                                  borderRadius:
                                                  BorderRadius.all(
                                                      Radius.circular(20))),
                                            ),
                                          ),
                                      ],
                                    )),
                                    DataCell(Row(
                                      children: [
                                        for (int i = 0;
                                        i < mData.jackBase.length;
                                        i++)
                                          Padding(
                                            padding: const EdgeInsets.all(8.0),
                                            child: Container(
                                              child: Padding(
                                                  padding:
                                                  const EdgeInsets.all(10),
                                                  child: Text(
                                                    mData.jackBase[i]
                                                        .toString(),
                                                    style: TextStyle(
                                                        fontWeight:
                                                        FontWeight.w300,
                                                        color: Colors.black),
                                                  )),
                                              decoration: BoxDecoration(
                                                  color: primaryColor
                                                      .withOpacity(0.1),
                                                  borderRadius:
                                                  BorderRadius.all(
                                                      Radius.circular(20))),
                                            ),
                                          ),
                                      ],
                                    )),
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
                                                      return AddProductDialog(
                                                        productData: mData,
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
                                                            "Delete data",
                                                            "warning");
                                                      } else {
                                                        deleteProduct(
                                                            productId: mData.id)
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
                                                                AddProductScreen
                                                                    .route);
                                                          } else {
                                                            ToastUtils
                                                                .showCustomToast(
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
                                                    title: "Delete Data",
                                                    subtitle:
                                                    "Do you want to delete this Product?");
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
                            await getProductList();
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
                : productList.isEmpty
                ? emptyWidget()
                : SizedBox(),
          ],
        ),
      );
    });
  }
}
