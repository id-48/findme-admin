import 'package:flutter/material.dart';
import 'package:find_me_admin/main.dart';
import 'package:find_me_admin/utils/Constants.dart';

class GetMobileBillingScreen extends StatefulWidget {
  @override
  State<GetMobileBillingScreen> createState() => _GetMobileBillingScreenState();
}

class _GetMobileBillingScreenState extends State<GetMobileBillingScreen> {
  ScrollController horizontalScrollController = ScrollController();

  // int currentPage = 1;
  // int totalPage = 1;
  // var perPage = 10;
  //
  // String userLogin = "";
  // String showRoomId = "";
  //
  // List<Billing> billingData = [];

  @override
  void initState() {
    init();
    super.initState();
  }

  Future<void> init() async {
    appStore.setSelectedMenuIndex(get_billing_index);
    // showRoomId = await getString("showroomId");
    // userLogin = await getString("userLogin");
    // if (userLogin == "admin") {
    //   print("userLogin:50 $userLogin");
    //   getBillingApiCall();
    // } else if (userLogin == "showRoom") {
    //   print("userLogin: $userLogin");
    //   getShowroomWiseApiCall();
    // }
  }

  // getBillingApiCall() async {
  //   await getBilling(limit: perPage, page: currentPage).then((value) {
  //     if (value.status == true) {
  //       billingData = value.billing;
  //       setState(() {});
  //     }
  //   });
  // }
  //
  // getShowroomWiseApiCall() async {
  //   await getShowroomWiseBilling(
  //           limit: perPage, page: currentPage, showroomId: showRoomId)
  //       .then((value) {
  //     if (value.status == true) {
  //       billingData = value.billing;
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
    return Scaffold(
        appBar: AppBar(
          title: Text("Billing Data"),
        ),
        body: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Padding(
              padding: const EdgeInsets.all(8.0),
              child: Text(
                "Showroom ID",
                style: TextStyle(fontSize: 18, fontWeight: FontWeight.w700),
              ),
            ),
            Container(
              margin: EdgeInsets.all(10),
              height: 250,
              decoration: BoxDecoration(
                color: Colors.white,
                boxShadow: [
                  BoxShadow(
                      color: Colors.black12,
                      offset: Offset(1, 2),
                      blurRadius: 12)
                ],
                borderRadius: BorderRadius.circular(12),
              ),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.center,
                mainAxisAlignment: MainAxisAlignment.start,
                children: [
                  Row(
                    children: [
                      Expanded(
                          flex: 1,
                          child: Padding(
                            padding: const EdgeInsets.all(8.0),
                            child: Column(
                              children: [
                                Row(
                                  crossAxisAlignment: CrossAxisAlignment.center,
                                  children: [
                                    Text(
                                      "Showroom",
                                      style: TextStyle(
                                          fontSize: 15,
                                          fontWeight: FontWeight.w600),
                                    ),
                                  ],
                                ),
                                Row(
                                  crossAxisAlignment: CrossAxisAlignment.center,
                                  children: [
                                    Text("xyz",
                                        style: TextStyle(
                                            fontSize: 15,
                                            fontWeight: FontWeight.w600)),
                                  ],
                                ),
                              ],
                            ),
                          )),
                      Expanded(
                          flex: 1,
                          child: Column(
                            children: [
                              Row(
                                children: [
                                  Text("Showroom name"),
                                ],
                              ),
                              Row(
                                children: [
                                  Text("xyz"),
                                ],
                              ),
                            ],
                          )),
                      Expanded(
                          flex: 1,
                          child: Column(
                            children: [
                              Row(
                                children: [
                                  Text("Showroom name"),
                                ],
                              ),
                              Row(
                                children: [
                                  Text("xyz"),
                                ],
                              ),
                            ],
                          ))
                    ],
                  ),
                ],
              ),
            )
          ],
        ));
  }
}
